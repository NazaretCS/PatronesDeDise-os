#ifndef TIPO_EVENTO_H
#define TIPO_EVENTO_H

// Tipos de novedad que un vuelo puede comunicar a sus observadores.
enum class tipoEvento {
    REPROGRAMACION,
    CAMBIO_PUERTA,
    CANCELACION
};

#endif
