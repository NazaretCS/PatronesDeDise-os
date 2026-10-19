#include <sstream>
#include <iomanip>
#include "pasajeBase.h"
#include "estadoPasaje.h"
#include "estadoEmitido.h"
#include "vuelo.h"
#include "pasajero.h"

using namespace std;

// pasajeBase(v, p, costo):
//     miVuelo = v
//     miPasajero = p
//     costoBase = costo
//     estadoActual = estadoEmitido.obtenerInstancia()
//
// Todo pasaje nace en estado Emitido.
pasajeBase::pasajeBase(vuelo* v, pasajero* p, float costo)
    : costoBase(costo), miVuelo(v), miPasajero(p) {
    static int contador = 1;
    ostringstream oss;
    oss << (v != nullptr ? v->getId() : "XX") << "-"
        << setw(4) << setfill('0') << contador++;
    codigo = oss.str();

    estadoActual = estadoEmitido::obtenerInstancia();
}

float pasajeBase::getCosto() const {
    return costoBase;
}

// cambiarEstado(e):
//     estadoActual = e
void pasajeBase::cambiarEstado(estadoPasaje* e) {
    estadoActual = e;
}

// hacerCheckIn():
//     estadoActual.hacerCheckIn(this)
void pasajeBase::hacerCheckIn() {
    estadoActual->hacerCheckIn(this);
}

// abordar():
//     estadoActual.abordar(this)
void pasajeBase::abordar() {
    estadoActual->abordar(this);
}

// cancelar():
//     estadoActual.cancelar(this)
void pasajeBase::cancelar() {
    estadoActual->cancelar(this);
}

string pasajeBase::getNombreEstado() const {
    return estadoActual->getNombreEstado();
}

string pasajeBase::getCodigo() const {
    return codigo;
}
