#include <stdio.h>
#include <string.h>
#include "movie.h"

void mostrarPelicula(Pelicula pelicula) {
    printf("ID: %d\n", pelicula.id_pelicula);
    printf("Título: %s\n", pelicula.titulo);
    printf("Sinopsis: %s\n", pelicula.sinopsis);
    printf("Horario: %s\n", pelicula.horario);
    printf("Número de sala: %d\n", pelicula.sala.numero_sala);
    printf("Capacidad de sala: %d\n", pelicula.sala.capacidad);
}