#ifndef PASAJE_FACTORY_H
#define PASAJE_FACTORY_H

class pasajeComponent;
class vuelo;
class pasajero;

// PATRON FACTORY METHOD  -  rol: Creador (abstracto)
//
// La creacion del producto NO es la responsabilidad principal del Creador:
// venderPasaje() contiene la logica de negocio de la venta y delega en el
// metodo fabrica crearPasaje() solamente la instanciacion.

class pasajeFactory {
protected:
    virtual pasajeComponent* crearPasaje(vuelo* v, pasajero* p) = 0;   // METODO FABRICA

public:
    virtual ~pasajeFactory() {}

    pasajeComponent* venderPasaje(vuelo* v, pasajero* p);
};

#endif
