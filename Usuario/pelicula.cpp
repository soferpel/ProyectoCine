#include "pelicula.h"
#include <string.h>

Pelicula::Pelicula(char* titulo, char* sinopsis, char* horario, int idSala)
{
    this->titulo = new char[strlen(titulo) + 1];
    strcpy(this->titulo, titulo);
    this->sinopsis = new char[strlen(sinopsis) + 1];
    strcpy(this->sinopsis, sinopsis);
    this->horario = new char[strlen(horario) + 1];
    strcpy(this->horario, horario);
    this->idSala = idSala;
}

Pelicula::~Pelicula()
{
    delete[] this->titulo;
    delete[] this->sinopsis;
    delete[] this->horario;
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

void Pelicula::setIdSala(int idSala)
{
    this->idSala = idSala;
}

int Pelicula::getIdPelicula()
{
    return this->idPelicula;
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

int Pelicula::getIdSala()
{
    return this->idSala;
}