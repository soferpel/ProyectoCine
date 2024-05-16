#include "pelicula.h"

Pelicula::Pelicula(char titulo[20], char sinopsis[100], char horario[20], int idSala)
{
    this->titulo = new char[20];
    strcpy(this->titulo, titulo);
    this->sinopsis = new char[100];
    strcpy(this->sinopsis, sinopsis);
    this->horario = new char[20];
    strcpy(this->horario, horario);
    this->idSala = idSala;
}

Pelicula::~Pelicula()
{
    delete[] this->titulo;
    delete[] this->sinopsis;
    delete[] this->horario;
}

void Pelicula::setTitulo(char titulo[20])
{
    strcpy(this->titulo, titulo);
}

void Pelicula::setSinopsis(char sinopsis[100])
{
    strcpy(this->sinopsis, sinopsis);
}

void Pelicula::setHorario(char horario[20])
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