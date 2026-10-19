#include "eventoVuelo.h"

using namespace std;

// eventoVuelo(id, t, dato):  [constructor]
//     idVuelo = id
//     tipo = t
//     segun tipo:
//         REPROGRAMACION: nuevoHorario = dato
//         CAMBIO_PUERTA:  nuevaPuerta  = dato
//         CANCELACION:    motivo       = dato
eventoVuelo::eventoVuelo(const string& id, tipoEvento t, const string& dato)
    : idVuelo(id), tipo(t) {
    switch (tipo) {
        case tipoEvento::REPROGRAMACION: nuevoHorario = dato; break;
        case tipoEvento::CAMBIO_PUERTA:  nuevaPuerta  = dato; break;
        case tipoEvento::CANCELACION:    motivo       = dato; break;
    }
}

tipoEvento eventoVuelo::getTipo() const {
    return tipo;
}

// Arma el texto legible que el observador mostrara al usuario.
string eventoVuelo::getMensaje() const {
    switch (tipo) {
        case tipoEvento::REPROGRAMACION:
            return "El vuelo " + idVuelo + " fue reprogramado. Nuevo horario: " + nuevoHorario;
        case tipoEvento::CAMBIO_PUERTA:
            return "El vuelo " + idVuelo + " cambio su puerta de embarque a: " + nuevaPuerta;
        case tipoEvento::CANCELACION:
            return "El vuelo " + idVuelo + " fue cancelado. Motivo: " + motivo;
    }
    return "";
}
