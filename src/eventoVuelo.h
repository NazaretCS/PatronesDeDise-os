#ifndef EVENTO_VUELO_H
#define EVENTO_VUELO_H

#include <string>
#include "tipoEvento.h"

using namespace std;

// PATRON OBSERVER  -  DTO del modelo PUSH
// El sujeto empuja un objeto inmutable con lo que cambio, en lugar de pasar
// this y exponer su estado interno (modelo PULL).

class eventoVuelo {
private:
    string idVuelo;
    tipoEvento  tipo;
    string nuevoHorario;
    string nuevaPuerta;
    string motivo;

public:
    eventoVuelo(const string& id, tipoEvento t, const string& dato);

    tipoEvento  getTipo() const;
    string getMensaje() const;
};

#endif
