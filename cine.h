#ifndef CINE_H
#define CINE_H

#include "provincia.h"

typedef struct {
    Provincia provincias[MAX_PROVINCIAS];
    int num_provincias;
} Cine;

void mostrarCinesPorProvincia(const Cine *cine, const char *provincia);

#endif
