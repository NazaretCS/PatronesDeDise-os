#include "accesoVIP.h"

using namespace std;

const float accesoVIP::COSTO_VIP = 24000.0f;

// accesoVIP(p, salon):
//     super(p)
//     salon = salon
//     costoAdicional = COSTO_VIP
accesoVIP::accesoVIP(pasajeComponent* p, const string& nombreSalon)
    : decoradorServicio(p), salon(nombreSalon), costoAdicional(COSTO_VIP) {}

// getCosto():
//     retornar envuelto.getCosto() + costoAdicional
float accesoVIP::getCosto() const {
    return envuelto->getCosto() + costoAdicional;
}

string accesoVIP::getDetalle() const {
    return envuelto->getDetalle() + " + Salon VIP " + salon;
}
