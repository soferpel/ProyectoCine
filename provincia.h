#ifndef PROVINCIA_H
#define PROVINCIA_H

#define MAX_CINES 3
#define MAX_PROVINCIAS 3
#define MAX_NOMBRE 50
#define MAX_DIRECCION 100

typedef struct {
    char nombre[MAX_NOMBRE];
    char direccion[MAX_DIRECCION];
} Cine;

typedef struct {
    char nombre[MAX_NOMBRE];
    Cine cines[MAX_CINES];
    int num_cines;
} Provincia;

void inicializarProvincias(Provincia provincias[MAX_PROVINCIAS]);

#endif
