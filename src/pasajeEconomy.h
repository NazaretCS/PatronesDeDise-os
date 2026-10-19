#ifndef PASAJE_ECONOMY_H
#define PASAJE_ECONOMY_H

#include "pasajeBase.h"

using namespace std;

// PATRON FACTORY METHOD -> rol: Producto Concreto  (lo crea economyFactory)
// PATRON DECORATOR      -> rol: Componente Concreto (puede ser envuelto)

class pasajeEconomy : public pasajeBase {
private:
    static const float TARIFA_BASE;
    int franquiciaEquipajeKg;

public:
    pasajeEconomy(vuelo* v, pasajero* p);

    string getDetalle() const override;
};

#endif
