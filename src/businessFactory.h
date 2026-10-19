#ifndef BUSINESS_FACTORY_H
#define BUSINESS_FACTORY_H

#include "pasajeFactory.h"

// PATRON FACTORY METHOD  -  rol: Creador Concreto

class businessFactory : public pasajeFactory {
protected:
    pasajeComponent* crearPasaje(vuelo* v, pasajero* p) override;
};

#endif
