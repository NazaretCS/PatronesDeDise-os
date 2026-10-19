#include <stdexcept>
#include "pasajeFactory.h"
#include "pasajeComponent.h"
#include "vuelo.h"
#include "pasajero.h"

using namespace std;

// venderPasaje(v, p):
//     si NO v.hayDisponibilidad():
//         lanzar excepcion(vuelo completo)
//     pc = crearPasaje(v, p)   // METODO FABRICA
//     v.reservarAsiento()
//     v.suscribir(p)           // alta en Observer
//     retornar pc
pasajeComponent* pasajeFactory::venderPasaje(vuelo* v, pasajero* p) {
    if (!v->hayDisponibilidad()) {
        throw logic_error("El vuelo " + v->getId() + " no tiene asientos disponibles");
    }
    pasajeComponent* pc = crearPasaje(v, p);
    v->reservarAsiento();
    v->suscribir(p);
    return pc;
}
