#ifndef PASAJE_BUSINESS_H
#define PASAJE_BUSINESS_H

#include "pasajeBase.h"

using namespace std;

// PATRON FACTORY METHOD -> rol: Producto Concreto  (lo crea businessFactory)
// PATRON DECORATOR      -> rol: Componente Concreto (puede ser envuelto)

class pasajeBusiness : public pasajeBase {
private:
    static const float TARIFA_BASE;
    bool accesoSalaEspera;

public:
    pasajeBusiness(vuelo* v, pasajero* p);

    string getDetalle() const override;
};

#endif
