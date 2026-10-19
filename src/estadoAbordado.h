#ifndef ESTADO_Abordado_H
#define ESTADO_Abordado_H

#include "estadoPasaje.h"

using namespace std;

// PATRON STATE     -> rol: Estado Concreto
// PATRON SINGLETON -> no posee atributos de instancia, por lo que una unica
//                     instancia es compartida por TODOS los pasajes (0..* --> 1)

class estadoAbordado : public estadoPasaje {
private:
    static estadoAbordado* instancia;

    estadoAbordado() {}                                       // constructor privado

public:
    estadoAbordado(const estadoAbordado&) = delete;               // sin copia
    estadoAbordado& operator=(const estadoAbordado&) = delete;    // sin asignacion

    static estadoAbordado* obtenerInstancia();

    void        hacerCheckIn(pasajeBase* ctx) override;
    void        abordar(pasajeBase* ctx) override;
    void        cancelar(pasajeBase* ctx) override;
    string getNombreEstado() const override;
};

#endif
