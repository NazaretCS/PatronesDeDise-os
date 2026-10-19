#include "sistemaAerolinea.h"
#include "vuelo.h"
#include "pasajero.h"
#include "pasajeFactory.h"
#include "pasajeComponent.h"

using namespace std;

sistemaAerolinea* sistemaAerolinea::instancia = nullptr;

// obtenerInstancia(): static
//     SI instancia == nulo ENTONCES
//         instancia = new sistemaAerolinea()
//     RETORNAR instancia
sistemaAerolinea* sistemaAerolinea::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new sistemaAerolinea();
    }
    return instancia;
}

sistemaAerolinea::~sistemaAerolinea() {
    for (vuelo* v : vuelos) {
        delete v;          // composicion: el sistema es duenio de los vuelos
    }
    vuelos.clear();
}

// Libera el Singleton al terminar el programa (evita fugas al salir).
void sistemaAerolinea::destruirInstancia() {
    delete instancia;
    instancia = nullptr;
}

void sistemaAerolinea::agregarVuelo(vuelo* v) {
    if (v != nullptr) vuelos.push_back(v);
}

// buscarVuelo(id)
//     PARA CADA v EN vuelos
//         SI v.getId() == id ENTONCES
//             RETORNAR v
//     RETORNAR nulo
vuelo* sistemaAerolinea::buscarVuelo(const string& id) const {
    for (vuelo* v : vuelos) {
        if (v->getId() == id) return v;
    }
    return nullptr;
}

// emitirPasaje(f, v, p)
//     RETORNAR f.venderPasaje(v, p)
//
// El sistema no conoce las clases concretas de pasaje: solo pide a la fabrica
// abstracta que realice la venta. venderPasaje() ya valida la disponibilidad,
// reserva el asiento y suscribe al pasajero (patron Observer).
pasajeComponent* sistemaAerolinea::emitirPasaje(pasajeFactory& f, vuelo* v, pasajero* p) {
    return f.venderPasaje(v, p);
}
