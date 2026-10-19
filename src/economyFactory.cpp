#include "economyFactory.h"
#include "pasajeEconomy.h"

// crearPasaje(v, p):
//     retornar new pasajeEconomy(v, p)
pasajeComponent* economyFactory::crearPasaje(vuelo* v, pasajero* p) {
    return new pasajeEconomy(v, p);
}
