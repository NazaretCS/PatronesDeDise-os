#ifndef EQUIPAJE_EXTRA_H
#define EQUIPAJE_EXTRA_H

#include "decoradorServicio.h"

using namespace std;

// PATRON DECORATOR  -  rol: Decorador Concreto
// Sobrescribe unicamente los metodos que necesita alterar.

class equipajeExtra : public decoradorServicio {
private:
    static const float TARIFA_KG;
    int   pesoKg;
    float costoAdicional;

public:
    equipajeExtra(pasajeComponent* p, int kg);

    float       getCosto() const override;
    string getDetalle() const override;
};

#endif
