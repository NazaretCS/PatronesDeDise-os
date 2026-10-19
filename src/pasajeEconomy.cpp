#include <sstream>
#include "pasajeEconomy.h"

using namespace std;

const float pasajeEconomy::TARIFA_BASE = 85000.0f;

pasajeEconomy::pasajeEconomy(vuelo* v, pasajero* p)
    : pasajeBase(v, p, TARIFA_BASE), franquiciaEquipajeKg(15) {}

string pasajeEconomy::getDetalle() const {
    ostringstream oss;
    oss << "Pasaje Economy [" << codigo << "] (franquicia "
        << franquiciaEquipajeKg << " kg)";
    return oss.str();
}
