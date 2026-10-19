#ifndef PASAJE_BASE_H
#define PASAJE_BASE_H

#include <string>
#include "pasajeComponent.h"

using namespace std;

class estadoPasaje;
class vuelo;
class pasajero;

// TRIPLE ROL:
//   PATRON FACTORY METHOD -> implementacion compartida de los Productos Concretos
//   PATRON DECORATOR      -> Componente Concreto
//   PATRON STATE          -> Contexto
//
// Clase ABSTRACTA: getDetalle() queda sin implementar para que cada clase de
// pasaje describa su propia politica.

class pasajeBase : public pasajeComponent {
protected:
    string   codigo;
    float         costoBase;
    estadoPasaje* estadoActual;   // instancia compartida (Singleton): NO se libera
    vuelo*        miVuelo;        // referencia, no propiedad
    pasajero*     miPasajero;     // referencia, no propiedad

public:
    pasajeBase(vuelo* v, pasajero* p, float costo);
    virtual ~pasajeBase() {}

    float       getCosto() const override;
    string getDetalle() const override = 0;   // abstracto

    void cambiarEstado(estadoPasaje* e);

    // El contexto NO decide: delega en el estado vigente.
    void hacerCheckIn() override;
    void abordar() override;
    void cancelar() override;

    string getNombreEstado() const;
    string getCodigo() const;
};

#endif
