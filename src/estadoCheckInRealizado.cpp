#include <stdexcept>
#include "estadoCheckInRealizado.h"
#include "estadoAbordado.h"
#include "estadoCancelado.h"
#include "pasajeBase.h"

using namespace std;

estadoCheckInRealizado* estadoCheckInRealizado::instancia = nullptr;

// obtenerInstancia(): static
//     SI instancia == nulo ENTONCES
//         instancia = new estadoCheckInRealizado()
//     RETORNAR instancia
estadoCheckInRealizado* estadoCheckInRealizado::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new estadoCheckInRealizado();
    }
    return instancia;
}

// hacerCheckIn(ctx)
//     LANZAR excepcion("El check-in ya fue realizado")
void estadoCheckInRealizado::hacerCheckIn(pasajeBase*) {
    throw logic_error("El check-in ya fue realizado");
}

// abordar(ctx)
//     ctx.cambiarEstado(estadoAbordado.obtenerInstancia())
void estadoCheckInRealizado::abordar(pasajeBase* ctx) {
    ctx->cambiarEstado(estadoAbordado::obtenerInstancia());
}

// cancelar(ctx)
//     ctx.cambiarEstado(estadoCancelado.obtenerInstancia())
void estadoCheckInRealizado::cancelar(pasajeBase* ctx) {
    ctx->cambiarEstado(estadoCancelado::obtenerInstancia());
}

string estadoCheckInRealizado::getNombreEstado() const {
    return "Check-in realizado";
}
