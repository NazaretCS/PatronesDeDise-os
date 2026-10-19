#ifndef DECORADOR_SERVICIO_H
#define DECORADOR_SERVICIO_H

#include "pasajeComponent.h"

using namespace std;

// PATRON DECORATOR  -  rol: Decorador (abstracto)
// Implementa la MISMA interfaz que envuelve, por eso el sistema lo trata como
// un pasaje comun. Su comportamiento por defecto es DELEGAR.
// PROPIEDAD: el decorador es duenio del componente envuelto y lo libera en su
// destructor, de modo que destruir el decorador mas externo destruye la pila.

class decoradorServicio : public pasajeComponent {
protected:
    pasajeComponent* envuelto;

public:
    explicit decoradorServicio(pasajeComponent* p);
    virtual ~decoradorServicio();

    float       getCosto() const override;
    string getDetalle() const override;
    void        hacerCheckIn() override;
    void        abordar() override;
    void        cancelar() override;
};

#endif
