#ifndef ESTADO_PASAJE_H
#define ESTADO_PASAJE_H

#include <string>

using namespace std;

class pasajeBase;

// PATRON STATE  -  rol: Estado
// Cada estado concreto conoce unicamente sus transiciones validas y recibe el
// contexto (ctx) para poder ordenarle el cambio de estado.

class estadoPasaje {
public:
    virtual ~estadoPasaje() {}

    virtual void        hacerCheckIn(pasajeBase* ctx) = 0;
    virtual void        abordar(pasajeBase* ctx) = 0;
    virtual void        cancelar(pasajeBase* ctx) = 0;
    virtual string getNombreEstado() const = 0;
};

#endif
