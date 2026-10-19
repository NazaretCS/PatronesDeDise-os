#include <iostream>
#include "vuelo.h"
#include "eventoVuelo.h"

using namespace std;

vuelo::vuelo(const string& id, const string& orig, const string& dest,
             const string& hora, const string& puerta, int asientos)
    : idVuelo(id), origen(orig), destino(dest), horario(hora),
      puertaEmbarque(puerta), asientosDisponibles(asientos) {}

// reprogramar(nuevoHorario, motivo):
//     horario = nuevoHorario
//     ev = new eventoVuelo(idVuelo, REPROGRAMACION, nuevoHorario)
//     notificar(ev)
void vuelo::reprogramar(const string& nuevoHorario, const string& motivo) {
    horario = nuevoHorario;
    cout << "\n[VUELO " << idVuelo << "] Reprogramado (" << motivo << ")\n";
    eventoVuelo ev(idVuelo, tipoEvento::REPROGRAMACION, nuevoHorario);
    notificar(ev);
}

// cambiarPuerta(nuevaPuerta):
//     puertaEmbarque = nuevaPuerta
//     ev = new eventoVuelo(idVuelo, CAMBIO_PUERTA, nuevaPuerta)
//     notificar(ev)
void vuelo::cambiarPuerta(const string& nuevaPuerta) {
    puertaEmbarque = nuevaPuerta;
    cout << "\n[VUELO " << idVuelo << "] Cambio de puerta de embarque\n";
    eventoVuelo ev(idVuelo, tipoEvento::CAMBIO_PUERTA, nuevaPuerta);
    notificar(ev);
}

// hayDisponibilidad(): bool
//     retorna asientosDisponibles > 0
bool vuelo::hayDisponibilidad() const {
    return asientosDisponibles > 0;
}

// reservarAsiento():
//     si hayDisponibilidad():
//         asientosDisponibles = asientosDisponibles - 1
void vuelo::reservarAsiento() {
    if (hayDisponibilidad()) {
        asientosDisponibles--;
    }
}

string vuelo::getId() const {
    return idVuelo;
}
