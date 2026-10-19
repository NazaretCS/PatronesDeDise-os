#include <algorithm>
#include "sujeto.h"
#include "eventoVuelo.h"

using namespace std;

// suscribir(o):
//     si o NO esta en observadores:
//         observadores.agregar(o)
void sujeto::suscribir(observadorVuelo* o) {
    if (o == nullptr) return;
    if (find(observadores.begin(), observadores.end(), o) == observadores.end()) {
        observadores.push_back(o);
    }
}

// desuscribir(o):
//     si o esta en observadores:
//         observadores.quitar(o)
void sujeto::desuscribir(observadorVuelo* o) {
    auto it = find(observadores.begin(), observadores.end(), o);
    if (it != observadores.end()) {
        observadores.erase(it);
    }
}

// notificar(ev):
//     para cada o en observadores:
//         o.actualizar(ev)
void sujeto::notificar(const eventoVuelo& ev) {
    for (observadorVuelo* o : observadores) {
        o->actualizar(ev);
    }
}
