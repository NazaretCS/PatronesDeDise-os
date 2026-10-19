#include <stdexcept>
#include "estadoCancelado.h"
#include "pasajeBase.h"

using namespace std;

estadoCancelado* estadoCancelado::instancia = nullptr;

// obtenerInstancia(): static
//     SI instancia == nulo ENTONCES
//         instancia = new estadoCancelado()
//     RETORNAR instancia
estadoCancelado* estadoCancelado::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new estadoCancelado();
    }
    return instancia;
}

// Estado terminal: un pasaje cancelado no hace check-in, no aborda y no se
// vuelve a cancelar.
void estadoCancelado::hacerCheckIn(pasajeBase*) {
    throw logic_error("El pasaje esta cancelado");
}

void estadoCancelado::abordar(pasajeBase*) {
    throw logic_error("El pasaje esta cancelado");
}

void estadoCancelado::cancelar(pasajeBase*) {
    throw logic_error("El pasaje ya esta cancelado");
}

string estadoCancelado::getNombreEstado() const {
    return "Cancelado";
}
