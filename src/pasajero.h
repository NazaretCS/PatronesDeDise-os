#ifndef PASAJERO_H
#define PASAJERO_H

#include <string>
#include "observadorVuelo.h"

using namespace std;

// PATRON OBSERVER  -  rol: Observador Concreto
// El pasajero NO consulta al vuelo: recibe el aviso sin pedirlo.

class pasajero : public observadorVuelo {
private:
    string nombre;
    string documento;
    string email;

public:
    pasajero(const string& nom, const string& doc, const string& mail);

    void actualizar(const eventoVuelo& ev) override;

    string getNombre() const;
};

#endif
