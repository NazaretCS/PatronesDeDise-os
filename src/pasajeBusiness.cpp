#include <sstream>
#include "pasajeBusiness.h"

using namespace std;

const float pasajeBusiness::TARIFA_BASE = 210000.0f;

pasajeBusiness::pasajeBusiness(vuelo* v, pasajero* p)
    : pasajeBase(v, p, TARIFA_BASE), accesoSalaEspera(true) {}

string pasajeBusiness::getDetalle() const {
    ostringstream oss;
    oss << "Pasaje Business [" << codigo << "]";
    if (accesoSalaEspera) oss << " (sala de espera incluida)";
    return oss.str();
}
