#include <iostream>
#include "pantallaAeropuerto.h"
#include "eventoVuelo.h"

using namespace std;

pantallaAeropuerto::pantallaAeropuerto(const string& sec) : sector(sec) {}

// actualizar(ev):
//     mostrarEnPantalla(sector, ev.getMensaje())
void pantallaAeropuerto::actualizar(const eventoVuelo& ev) {
    cout << "   -> [pantalla sector " << sector << "] " << ev.getMensaje() << "\n";
}
