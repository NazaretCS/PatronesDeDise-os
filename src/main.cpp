#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>

#include "sistemaAerolinea.h"
#include "vuelo.h"
#include "pasajero.h"
#include "pantallaAeropuerto.h"
#include "economyFactory.h"
#include "businessFactory.h"
#include "pasajeComponent.h"
#include "pasajeBase.h"
#include "equipajeExtra.h"
#include "accesoVIP.h"
#include "estadoEmitido.h"
#include "estadoAbordado.h"

using namespace std;

// Utilidades de presentacion

static void titulo(const string& t) {
    cout << "\n";
    cout << "===========================================================\n";
    cout << " " << t << "\n";
    cout << "===========================================================\n";
}

static void mostrar(const string& etiqueta, pasajeComponent* pc) {
    cout << "   " << left << setw(10) << etiqueta
              << pc->getDetalle() << "\n"
              << "   " << setw(10) << " "
              << "Costo total: $" << fixed << setprecision(2)
              << pc->getCosto() << "\n";
}

// Ejecuta una operacion del ciclo de vida mostrando el resultado o el motivo
// por el cual el estado actual la rechaza.
static void intentar(const string& accion, pasajeBase* p, void (pasajeBase::*op)()) {
    try {
        (p->*op)();
        cout << "   [OK]    " << accion << " -> estado: "
                  << p->getNombreEstado() << "\n";
    } catch (const logic_error& e) {
        cout << "   [ERROR] " << accion << " -> " << e.what() << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  SISTEMA DE GESTION DE VUELOS Y PASAJES AERONAUTICOS\n";
    cout << "  Trabajo Final - Patrones de Diseno - FACET UNT\n";

    // -----------------------------------------------------------------------
    titulo("1. SINGLETON - punto de acceso unico");
    // -----------------------------------------------------------------------
    sistemaAerolinea* sistema = sistemaAerolinea::obtenerInstancia();
    sistemaAerolinea* otroAcceso = sistemaAerolinea::obtenerInstancia();

    cout << "   Primera llamada a obtenerInstancia(): " << sistema << "\n";
    cout << "   Segunda llamada a obtenerInstancia(): " << otroAcceso << "\n";
    cout << "   Son la misma instancia? "
              << (sistema == otroAcceso ? "SI" : "NO") << "\n";

    vuelo* ar1420 = new vuelo("AR1420", "Tucuman", "Buenos Aires",
                              "08:30", "A2", 3);
    vuelo* ar2255 = new vuelo("AR2255", "Buenos Aires", "Cordoba",
                              "14:10", "B7", 1);
    sistema->agregarVuelo(ar1420);
    sistema->agregarVuelo(ar2255);
    cout << "   Vuelos registrados: AR1420 y AR2255\n";
    cout << "   buscarVuelo(\"AR2255\") devuelve: "
              << sistema->buscarVuelo("AR2255")->getId() << "\n";

    // -----------------------------------------------------------------------
    titulo("2. FACTORY METHOD - creacion desacoplada de pasajes");
    // -----------------------------------------------------------------------
    economyFactory  fabricaEconomy;
    businessFactory fabricaBusiness;

    pasajero natalia("Rollan Natalia", "35.111.222", "nati@mail.com");
    pasajero nestor("Campos Nazaret", "36.333.444", "naza@mail.com");
    pasajero juan("Gramajo Juani", "37.555.666", "juani@mail.com");

    // El sistema solo conoce la abstraccion pasajeFactory y el tipo de retorno
    // pasajeComponent: nunca nombra a pasajeEconomy ni a pasajeBusiness.
    pasajeComponent* pasaje1 = sistema->emitirPasaje(fabricaEconomy, ar1420, &natalia);
    pasajeComponent* pasaje2 = sistema->emitirPasaje(fabricaBusiness, ar1420, &nestor);

    cout << "   Se emitieron dos pasajes usando la misma llamada,\n";
    cout << "   cambiando unicamente la fabrica concreta:\n\n";
    mostrar("Pasaje 1:", pasaje1);
    mostrar("Pasaje 2:", pasaje2);

    // -----------------------------------------------------------------------
    titulo("3. DECORATOR - servicios adicionales acumulativos");
    // -----------------------------------------------------------------------
    cout << "   Antes de decorar:\n";
    mostrar("Pasaje 1:", pasaje1);

    pasaje1 = new equipajeExtra(pasaje1, 23);
    cout << "\n   Despues de agregar equipaje extra (23 kg):\n";
    mostrar("Pasaje 1:", pasaje1);

    pasaje1 = new accesoVIP(pasaje1, "Andes");
    cout << "\n   Despues de agregar acceso al Salon VIP:\n";
    mostrar("Pasaje 1:", pasaje1);

    cout << "\n   La llamada a getCosto() recorrio la pila de decoradores\n";
    cout << "   hasta el pasaje base y volvio sumando cada servicio.\n";

    // -----------------------------------------------------------------------
    titulo("4. STATE - ciclo de vida del pasaje");
    // -----------------------------------------------------------------------
    // pasaje2 no esta decorado, por eso puede consultarse su estado directamente.
    pasajeBase* p2 = dynamic_cast<pasajeBase*>(pasaje2);

    cout << "   Estado inicial del pasaje 2: " << p2->getNombreEstado() << "\n\n";
    cout << "   Recorrido valido:\n";
    intentar("abordar()      ", p2, &pasajeBase::abordar);      // rechazado
    intentar("hacerCheckIn() ", p2, &pasajeBase::hacerCheckIn); // aceptado
    intentar("abordar()      ", p2, &pasajeBase::abordar);      // aceptado

    cout << "\n   Operaciones que el estado actual rechaza:\n";
    intentar("hacerCheckIn() ", p2, &pasajeBase::hacerCheckIn);
    intentar("cancelar()     ", p2, &pasajeBase::cancelar);

    // El decorador reenvia las operaciones de estado al pasaje envuelto.
    cout << "\n   El mismo ciclo a traves de la pila de decoradores:\n";
    try {
        pasaje1->hacerCheckIn();
        cout << "   [OK]    hacerCheckIn() reenviado por los decoradores\n";
        pasaje1->cancelar();
        cout << "   [OK]    cancelar() reenviado por los decoradores\n";
    } catch (const logic_error& e) {
        cout << "   [ERROR] " << e.what() << "\n";
    }

    // -----------------------------------------------------------------------
    titulo("5. SINGLETON en los estados - una instancia para todos");
    // -----------------------------------------------------------------------
    pasajeComponent* pasaje3 = sistema->emitirPasaje(fabricaEconomy, ar2255, &juan);
    pasajeBase* p3 = dynamic_cast<pasajeBase*>(pasaje3);

    cout << "   estadoEmitido::obtenerInstancia() = "
              << estadoEmitido::obtenerInstancia() << "\n";
    cout << "   estadoAbordado::obtenerInstancia() = "
              << estadoAbordado::obtenerInstancia() << "\n";
    cout << "   Pasaje 3 recien emitido, estado: " << p3->getNombreEstado() << "\n";
    cout << "   Todos los pasajes en 'Emitido' comparten ese unico objeto:\n";
    cout << "   un vuelo de 200 pasajeros usa 4 objetos de estado, no 200.\n";

    // -----------------------------------------------------------------------
    titulo("6. OBSERVER - notificacion automatica de novedades");
    // -----------------------------------------------------------------------
    pantallaAeropuerto pantallaEmbarque("Embarque Nacional");
    ar1420->suscribir(&pantallaEmbarque);

    cout << "   Suscriptos al vuelo AR1420: los pasajeros que compraron\n";
    cout << "   (alta automatica en venderPasaje) y una pantalla del aeropuerto.\n";

    ar1420->reprogramar("11:45", "condiciones meteorologicas");
    ar1420->cambiarPuerta("A7");

    cout << "\n   Natalia se da de baja de las notificaciones...\n";
    ar1420->desuscribir(&natalia);
    ar1420->cambiarPuerta("C1");

    // -----------------------------------------------------------------------
    titulo("7. VALIDACION DE NEGOCIO - sin asientos disponibles");
    // -----------------------------------------------------------------------
    try {
        pasajero tardio("Pasajero Tardio", "40.000.111", "tardio@mail.com");
        pasajeComponent* extra = sistema->emitirPasaje(fabricaEconomy, ar2255, &tardio);
        delete extra;
    } catch (const logic_error& e) {
        cout << "   [ERROR] " << e.what() << "\n";
        cout << "   venderPasaje() valido la disponibilidad antes de crear nada.\n";
    }

    // -----------------------------------------------------------------------
    titulo("8. LIBERACION DE MEMORIA");
    // -----------------------------------------------------------------------
    // Destruir el decorador mas externo destruye toda la pila hasta el pasaje base.
    delete pasaje1;
    cout << "   Pasaje 1: se destruyo el decorador mas externo y con el\n";
    cout << "             toda la pila (accesoVIP -> equipajeExtra -> pasajeEconomy).\n";
    delete pasaje2;
    delete pasaje3;
    cout << "   Pasajes 2 y 3 liberados.\n";

    // El sistema es duenio de los vuelos (composicion) y los libera.
    sistemaAerolinea::destruirInstancia();
    cout << "   sistemaAerolinea liberado junto con sus vuelos.\n";
    cout << "   Los objetos de estado son Singleton compartidos: ningun\n";
    cout << "   pasaje los destruye, viven hasta el fin del programa.\n\n";

    return 0;
}
