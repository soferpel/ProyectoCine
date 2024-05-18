#include "pelicula.h"
#include <string.h>

Pelicula::Pelicula(char* titulo, char* sinopsis, char* horario, char* idSala)
{
    this->titulo = new char[strlen(titulo) + 1];
    strcpy(this->titulo, titulo);
    this->sinopsis = new char[strlen(sinopsis) + 1];
    strcpy(this->sinopsis, sinopsis);
    this->horario = new char[strlen(horario) + 1];
    strcpy(this->horario, horario);
    this->idSala = new char[strlen(idSala) + 1];
    strcpy(this->idSala, idSala);
}

Pelicula::~Pelicula()
{
    delete[] this->titulo;
    delete[] this->sinopsis;
    delete[] this->horario;
    delete[] this->idSala;
}

void Pelicula::setTitulo(char* titulo)
{
    strcpy(this->titulo, titulo);
}

void Pelicula::setSinopsis(char* sinopsis)
{
    strcpy(this->sinopsis, sinopsis);
}

void Pelicula::setHorario(char* horario)
{
    strcpy(this->horario, horario);
}

void Pelicula::setIdSala(char* idSala)
{
    strcpy(this->idSala, idSala);
}

char* Pelicula::getTitulo()
{
    return this->titulo;
}

char* Pelicula::getSinopsis()
{
    return this->sinopsis;
}

char* Pelicula::getHorario()
{
    return this->horario;
}

char* Pelicula::getIdSala()
{
    return this->idSala;
}