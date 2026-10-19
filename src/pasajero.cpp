#include <iostream>
#include "pasajero.h"
#include "eventoVuelo.h"

using namespace std;

pasajero::pasajero(const string& nom, const string& doc, const string& mail)
    : nombre(nom), documento(doc), email(mail) {}

// actualizar(ev):
//     notificarPorEmail(email, ev.getMensaje())
void pasajero::actualizar(const eventoVuelo& ev) {
    cout << "   -> [email a " << email << "] " << ev.getMensaje() << "\n";
}

string pasajero::getNombre() const {
    return nombre;
}
