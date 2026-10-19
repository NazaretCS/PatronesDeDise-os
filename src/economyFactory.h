#ifndef ECONOMY_FACTORY_H
#define ECONOMY_FACTORY_H

#include "pasajeFactory.h"

// PATRON FACTORY METHOD  -  rol: Creador Concreto
// El tipo de retorno declarado sigue siendo pasajeComponent: el cliente nunca
// conoce la clase concreta.

class economyFactory : public pasajeFactory {
protected:
    pasajeComponent* crearPasaje(vuelo* v, pasajero* p) override;
};

#endif
