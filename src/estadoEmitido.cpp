#include <stdexcept>
#include "estadoEmitido.h"
#include "estadoCheckInRealizado.h"
#include "estadoCancelado.h"
#include "pasajeBase.h"

using namespace std;

estadoEmitido* estadoEmitido::instancia = nullptr;

// obtenerInstancia(): static
//     SI instancia == nulo ENTONCES
//         instancia = new estadoEmitido()
//     RETORNAR instancia
estadoEmitido* estadoEmitido::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new estadoEmitido();
    }
    return instancia;
}

// hacerCheckIn(ctx)
//     ctx.cambiarEstado(estadoCheckInRealizado.obtenerInstancia())
void estadoEmitido::hacerCheckIn(pasajeBase* ctx) {
    ctx->cambiarEstado(estadoCheckInRealizado::obtenerInstancia());
}

// abordar(ctx)
//     LANZAR excepcion("Debe hacer el check-in antes de abordar")
void estadoEmitido::abordar(pasajeBase*) {
    throw logic_error("Debe hacer el check-in antes de abordar");
}

// cancelar(ctx)
//     ctx.cambiarEstado(estadoCancelado.obtenerInstancia())
void estadoEmitido::cancelar(pasajeBase* ctx) {
    ctx->cambiarEstado(estadoCancelado::obtenerInstancia());
}

string estadoEmitido::getNombreEstado() const {
    return "Emitido";
}
