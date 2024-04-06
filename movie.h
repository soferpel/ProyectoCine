#ifndef MOVIE_H
#define MOVIE_H

#define MAX_TITLE_LENGTH 100
#define MAX_SYNOPSIS_LENGTH 500
#define MAX_SCHEDULE_LENGTH 50

typedef struct {
    int numero_sala;
    int capacidad;
} Sala;

typedef struct {
    int id_pelicula;
    char titulo[MAX_TITLE_LENGTH];
    char sinopsis[MAX_SYNOPSIS_LENGTH];
    char horario[MAX_SCHEDULE_LENGTH];
    Sala sala;
} Pelicula;

void mostrarPelicula(Pelicula pelicula);
Pelicula crearPelicula(int id, const char *titulo, const char *sinopsis, const char *horario, int numero_sala, int capacidad);

#endif 