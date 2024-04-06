#include "asiento.h"

void inicializarAsiento(Asiento *asiento, int fila, int columna) {
    asiento->fila = fila;
    asiento->columna = columna;
    asiento->ocupado = false;
}

void reservarAsiento(Asiento *asiento) {
    asiento->ocupado = true;
}

void liberarAsiento(Asiento *asiento) {
    asiento->ocupado = false;
}
