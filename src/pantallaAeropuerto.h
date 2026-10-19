#ifndef PANTALLA_AEROPUERTO_H
#define PANTALLA_AEROPUERTO_H

#include <string>
#include "observadorVuelo.h"

using namespace std;

// PATRON OBSERVER  -  rol: Observador Concreto
// Segundo observador: pudo sumarse al sistema sin modificar la clase vuelo.

class pantallaAeropuerto : public observadorVuelo {
private:
    string sector;

public:
    explicit pantallaAeropuerto(const string& sec);

    void actualizar(const eventoVuelo& ev) override;
};

#endif
