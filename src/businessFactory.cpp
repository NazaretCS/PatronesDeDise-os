#include "businessFactory.h"
#include "pasajeBusiness.h"

// crearPasaje(v, p):
//     retornar new pasajeBusiness(v, p)
pasajeComponent* businessFactory::crearPasaje(vuelo* v, pasajero* p) {
    return new pasajeBusiness(v, p);
}
