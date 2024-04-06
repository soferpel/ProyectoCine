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

Pelicula crearPelicula(int id, const char *titulo, const char *sinopsis, const char *horario, int numero_sala, int capacidad) {
    Pelicula nuevaPelicula;
    nuevaPelicula.id_pelicula = id;
    strncpy(nuevaPelicula.titulo, titulo, MAX_TITLE_LENGTH);
    nuevaPelicula.titulo[MAX_TITLE_LENGTH - 1] = '\0';  // Asegurar que el título esté terminado correctamente
    strncpy(nuevaPelicula.sinopsis, sinopsis, MAX_SYNOPSIS_LENGTH);
    nuevaPelicula.sinopsis[MAX_SYNOPSIS_LENGTH - 1] = '\0';  // Asegurar que la sinopsis esté terminada correctamente
    strncpy(nuevaPelicula.horario, horario, MAX_SCHEDULE_LENGTH);
    nuevaPelicula.horario[MAX_SCHEDULE_LENGTH - 1] = '\0';  // Asegurar que el horario esté terminado correctamente
    nuevaPelicula.sala.numero_sala = numero_sala;
    nuevaPelicula.sala.capacidad = capacidad;

    return nuevaPelicula;
}