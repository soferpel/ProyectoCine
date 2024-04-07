#ifndef CINE_H
#define CINE_H

typedef struct 
{
    int idCineInt;
    char idCineChar[4];
    char nombreCine[20];
    char direccionCine[20];
    char ciudadCine[20];

} Cine;

void anadirCine(PathDB rutaDB); 
void modificarCine(PathDB rutaDB);
void validarCine(PathDB rutaDB);
int callbackCine(void *data, int argc, char **argv, char **col_names);

#endif