#ifndef SALA_H
#define SALA_H

#include "asiento.h"

#define MAX_FILAS 10
#define MAX_COLUMNAS 10

typedef struct {
    Asiento asientos[MAX_FILAS][MAX_COLUMNAS];
    int num_filas;
    int num_columnas;
} Sala;

void inicializarSala(Sala *sala, int filas, int columnas);
void mostrarAsientosDisponibles(Sala sala);
void reservarAsientoEnSala(Sala *sala, int fila, int columna);

#endif 
