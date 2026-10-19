#ifndef ESTADO_Cancelado_H
#define ESTADO_Cancelado_H

#include "estadoPasaje.h"

using namespace std;

// PATRON STATE     -> rol: Estado Concreto
// PATRON SINGLETON -> no posee atributos de instancia, por lo que una unica
//                     instancia es compartida por TODOS los pasajes (0..* --> 1)

class estadoCancelado : public estadoPasaje {
private:
    static estadoCancelado* instancia;

    estadoCancelado() {}                                       // constructor privado

public:
    estadoCancelado(const estadoCancelado&) = delete;               // sin copia
    estadoCancelado& operator=(const estadoCancelado&) = delete;    // sin asignacion

    static estadoCancelado* obtenerInstancia();

    void        hacerCheckIn(pasajeBase* ctx) override;
    void        abordar(pasajeBase* ctx) override;
    void        cancelar(pasajeBase* ctx) override;
    string getNombreEstado() const override;
};

#endif
