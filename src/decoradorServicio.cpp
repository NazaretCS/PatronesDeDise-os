#include "decoradorServicio.h"

using namespace std;

// decoradorServicio(p):
//     envuelto = p
decoradorServicio::decoradorServicio(pasajeComponent* p) : envuelto(p) {}

decoradorServicio::~decoradorServicio() {
    delete envuelto;   // el decorador es dueño de lo que envuelve
}

// Comportamiento por defecto: DELEGAR. Las subclases agregan.
float decoradorServicio::getCosto() const {
    return envuelto->getCosto();
}

string decoradorServicio::getDetalle() const {
    return envuelto->getDetalle();
}

void decoradorServicio::hacerCheckIn() {
    envuelto->hacerCheckIn();
}

void decoradorServicio::abordar() {
    envuelto->abordar();
}

void decoradorServicio::cancelar() {
    envuelto->cancelar();
}
