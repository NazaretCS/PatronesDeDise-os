#ifndef SISTEMA_AEROLINEA_H
#define SISTEMA_AEROLINEA_H

#include <string>
#include <vector>

using namespace std;

class vuelo;
class pasajero;
class pasajeFactory;
class pasajeComponent;

// PATRON SINGLETON  -  punto de acceso unico y global al catalogo de vuelos.
// COMPOSICION: es duenio de los vuelos y los libera en su destructor.

class sistemaAerolinea {
private:
    static sistemaAerolinea* instancia;

    vector<vuelo*> vuelos;

    sistemaAerolinea() {}                                     // constructor privado
    ~sistemaAerolinea();

public:
    sistemaAerolinea(const sistemaAerolinea&) = delete;            // sin copia
    sistemaAerolinea& operator=(const sistemaAerolinea&) = delete; // sin asignacion

    static sistemaAerolinea* obtenerInstancia();
    static void              destruirInstancia();

    void   agregarVuelo(vuelo* v);
    vuelo* buscarVuelo(const string& id) const;

    pasajeComponent* emitirPasaje(pasajeFactory& f, vuelo* v, pasajero* p);
};

#endif
