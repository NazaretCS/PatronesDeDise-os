#ifndef ESTADO_Emitido_H
#define ESTADO_Emitido_H

#include "estadoPasaje.h"

using namespace std;

// PATRON STATE     -> rol: Estado Concreto
// PATRON SINGLETON -> no posee atributos de instancia, por lo que una unica
//                     instancia es compartida por TODOS los pasajes (0..* --> 1)

class estadoEmitido : public estadoPasaje {
private:
    static estadoEmitido* instancia;

    estadoEmitido() {}                                       // constructor privado

public:
    estadoEmitido(const estadoEmitido&) = delete;               // sin copia
    estadoEmitido& operator=(const estadoEmitido&) = delete;    // sin asignacion

    static estadoEmitido* obtenerInstancia();

    void        hacerCheckIn(pasajeBase* ctx) override;
    void        abordar(pasajeBase* ctx) override;
    void        cancelar(pasajeBase* ctx) override;
    string getNombreEstado() const override;
};

#endif
