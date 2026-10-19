#ifndef ESTADO_CheckInRealizado_H
#define ESTADO_CheckInRealizado_H

#include "estadoPasaje.h"

using namespace std;

// PATRON STATE     -> rol: Estado Concreto
// PATRON SINGLETON -> no posee atributos de instancia, por lo que una unica
//                     instancia es compartida por TODOS los pasajes (0..* --> 1)

class estadoCheckInRealizado : public estadoPasaje {
private:
    static estadoCheckInRealizado* instancia;

    estadoCheckInRealizado() {}                                       // constructor privado

public:
    estadoCheckInRealizado(const estadoCheckInRealizado&) = delete;               // sin copia
    estadoCheckInRealizado& operator=(const estadoCheckInRealizado&) = delete;    // sin asignacion

    static estadoCheckInRealizado* obtenerInstancia();

    void        hacerCheckIn(pasajeBase* ctx) override;
    void        abordar(pasajeBase* ctx) override;
    void        cancelar(pasajeBase* ctx) override;
    string getNombreEstado() const override;
};

#endif
