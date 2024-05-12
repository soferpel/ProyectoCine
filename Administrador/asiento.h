#ifndef ASIENTO_H
#define ASIENTO_H
#include "configuracion.h"

typedef struct {
    char idAsientoChar[5];
    int idAsientoInt;
    char filaAsientoChar[3];
    int filaAsientoInt;
    char numeroAsientoChar[3];
    int numeroAsientoInt;
    char fechaAsiento[11];

} Asiento;

void anadirAsiento(PathDB rutaDB);
void modificarAsiento(PathDB rutaDB);
void validarAsiento(PathDB rutaDB);
int callbackAsiento(void *data, int argc, char **argv, char **col_names);

#endif