#include <stdexcept>
#include "estadoAbordado.h"
#include "pasajeBase.h"

using namespace std;

estadoAbordado* estadoAbordado::instancia = nullptr;

// obtenerInstancia(): static
//     SI instancia == nulo ENTONCES
//         instancia = new estadoAbordado()
//     RETORNAR instancia
estadoAbordado* estadoAbordado::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new estadoAbordado();
    }
    return instancia;
}

// Estado terminal del recorrido normal: ninguna transicion es valida.
void estadoAbordado::hacerCheckIn(pasajeBase*) {
    throw logic_error("El pasaje ya fue abordado");
}

void estadoAbordado::abordar(pasajeBase*) {
    throw logic_error("El pasaje ya fue abordado");
}

void estadoAbordado::cancelar(pasajeBase*) {
    throw logic_error("No se puede cancelar un pasaje abordado");
}

string estadoAbordado::getNombreEstado() const {
    return "Abordado";
}
