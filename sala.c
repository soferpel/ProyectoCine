#include "sala.h"
#include <stdio.h>

void inicializarSala(Sala *sala, int filas, int columnas) {
    sala->num_filas = filas;
    sala->num_columnas = columnas;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            inicializarAsiento(&sala->asientos[i][j], i + 1, j + 1);
        }
    }
}

void mostrarAsientosDisponibles(Sala sala) {
    printf("Asientos disponibles:\n");

    for (int i = 0; i < sala.num_filas; i++) {
        for (int j = 0; j < sala.num_columnas; j++) {
            if (!sala.asientos[i][j].ocupado) {
                printf("Fila %d, Columna %d\n", sala.asientos[i][j].fila, sala.asientos[i][j].columna);
            }
        }
    }
}

void reservarAsientoEnSala(Sala *sala, int fila, int columna) {
    if (fila > 0 && fila <= sala->num_filas && columna > 0 && columna <= sala->num_columnas) {
        reservarAsiento(&sala->asientos[fila - 1][columna - 1]);
    } else {
        printf("Asiento no válido.\n");
    }
}
