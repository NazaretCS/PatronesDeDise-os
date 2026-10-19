#ifndef ACCESO_VIP_H
#define ACCESO_VIP_H

#include <string>
#include "decoradorServicio.h"

using namespace std;

// PATRON DECORATOR  -  rol: Decorador Concreto

class accesoVIP : public decoradorServicio {
private:
    static const float COSTO_VIP;
    string salon;
    float       costoAdicional;

public:
    accesoVIP(pasajeComponent* p, const string& nombreSalon);

    float       getCosto() const override;
    string getDetalle() const override;
};

#endif
