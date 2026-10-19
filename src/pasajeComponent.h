#ifndef PASAJE_COMPONENT_H
#define PASAJE_COMPONENT_H

#include <string>

using namespace std;

// DOBLE ROL:
//   PATRON FACTORY METHOD -> rol: Producto  (tipo que devuelve el metodo fabrica)
//   PATRON DECORATOR      -> rol: Componente (interfaz comun a pasajes y decoradores)
//
// cancelar() forma parte de la interfaz: si el decorador no la reenviara, el
// objeto envuelto quedaria inalcanzable para esa operacion.

class pasajeComponent {
public:
    virtual ~pasajeComponent() {}

    virtual float       getCosto() const = 0;
    virtual string getDetalle() const = 0;
    virtual void        hacerCheckIn() = 0;
    virtual void        abordar() = 0;
    virtual void        cancelar() = 0;
};

#endif
