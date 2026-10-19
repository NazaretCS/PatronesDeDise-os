#ifndef SUJETO_H
#define SUJETO_H

#include <vector>
#include "observadorVuelo.h"

using namespace std;

class eventoVuelo;

// PATRON OBSERVER  -  rol: Sujeto (abstracto)
// Concentra la logica de suscripcion y notificacion para que sea reutilizable
// por cualquier clase observable del sistema.
// AGREGACION: el sujeto referencia a sus observadores, NO es su duenio.

class sujeto {
protected:
    vector<observadorVuelo*> observadores;

    void notificar(const eventoVuelo& ev);

public:
    virtual ~sujeto() {}

    void suscribir(observadorVuelo* o);
    void desuscribir(observadorVuelo* o);
};

#endif
