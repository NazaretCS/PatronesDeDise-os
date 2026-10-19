#include <sstream>
#include "equipajeExtra.h"

using namespace std;

const float equipajeExtra::TARIFA_KG = 3500.0f;

// equipajeExtra(p, pesoKg):
//     super(p)
//     pesoKg = pesoKg
//     costoAdicional = TARIFA_KG * pesoKg
equipajeExtra::equipajeExtra(pasajeComponent* p, int kg)
    : decoradorServicio(p), pesoKg(kg), costoAdicional(TARIFA_KG * kg) {}

// getCosto():
//     retornar envuelto.getCosto() + costoAdicional
float equipajeExtra::getCosto() const {
    return envuelto->getCosto() + costoAdicional;
}

// getDetalle():
//     retornar envuelto.getDetalle() + " + Equipaje pesoKg kg"
string equipajeExtra::getDetalle() const {
    ostringstream oss;
    oss << envuelto->getDetalle() << " + Equipaje " << pesoKg << " kg";
    return oss.str();
}
