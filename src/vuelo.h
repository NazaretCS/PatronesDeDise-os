#ifndef VUELO_H
#define VUELO_H

#include <string>
#include "sujeto.h"

using namespace std;

// PATRON OBSERVER  -  rol: Sujeto Concreto
// Cada metodo que modifica un dato de itinerario construye un eventoVuelo y lo
// empuja hacia los observadores.

class vuelo : public sujeto {
private:
    string idVuelo;
    string origen;
    string destino;
    string horario;
    string puertaEmbarque;
    int         asientosDisponibles;

public:
        vuelo(const string& id, const string& orig, const string& dest,
            const string& hora, const string& puerta, int asientos);

    void reprogramar(const string& nuevoHorario, const string& motivo);
    void cambiarPuerta(const string& nuevaPuerta);

    bool hayDisponibilidad() const;
    void reservarAsiento();

    string getId() const;
};

#endif
