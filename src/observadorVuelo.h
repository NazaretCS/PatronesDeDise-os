#ifndef OBSERVADOR_VUELO_H
#define OBSERVADOR_VUELO_H

class eventoVuelo;

// PATRON OBSERVER  -  rol: Observador
// Interfaz que deben implementar todos los interesados en las novedades de un
// vuelo. El sujeto conoce unicamente este tipo, nunca las clases concretas.

class observadorVuelo {
public:
    virtual ~observadorVuelo() {}
    virtual void actualizar(const eventoVuelo& ev) = 0;
};

#endif
