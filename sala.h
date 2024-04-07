#ifndef SALA_H
#define SALA_H

typedef struct 
{
    int idSalaInt;
    char idSalaChar[4];
    char numeroSalaChar[3];
    int numeroSalaInt;
    char nColumnasSalaChar[3];
    int nColumnasSalaInt;
    char nFilasSalaChar[3];
    int nFilasSalaInt;

} Sala;

void anadirSala(PathDB rutaDB) 
void modificarSala(PathDB rutaDB)
void validarSala(PathDB rutaDB)
int callbackSala(void *data, int argc, char **argv, char **col_names)

#endif
