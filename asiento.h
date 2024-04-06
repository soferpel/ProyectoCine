#ifndef ASIENTO_H
#define ASIENTO_H

#include <stdbool.h>

typedef struct {
    int fila;
    int columna;
    bool ocupado;
} Asiento;

void inicializarAsiento(Asiento *asiento, int fila, int columna);
void reservarAsiento(Asiento *asiento);
void liberarAsiento(Asiento *asiento);

#endif 
