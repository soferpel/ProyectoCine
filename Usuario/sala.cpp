#include "sala.h"
#include <cstring>

Sala::Sala(char* numeroSala, char* nColumnasSala, char* nFilasSala, char* idCine)
{
    this->idCine =  new char[strlen(idCine) + 1];
    strcpy(this->idCine, idCine);
    this->numeroSala =  new char[strlen(numeroSala) + 1];
    strcpy(this->numeroSala, numeroSala);
    this->nColumnasSala =  new char[strlen(nColumnasSala) + 1];
    strcpy(this->nColumnasSala, nColumnasSala);
    this->nFilasSala =  new char[strlen(nFilasSala) + 1];
    strcpy(this->nFilasSala, nFilasSala);
}

Sala::Sala()
{
    this->idCine =  new char[strlen(idCine) + 1];
    this->numeroSala =  new char[strlen(numeroSala) + 1];
    this->nColumnasSala =  new char[strlen(nColumnasSala) + 1];
    this->nFilasSala =  new char[strlen(nFilasSala) + 1];
}

Sala::~Sala()
{
    delete[] this->numeroSala;
    delete[] this->nColumnasSala;
    delete[] this->nFilasSala;
    delete[] this->idCine;
}

void Sala::setNumeroSala(char* numeroSala)
{
    strcpy(this->numeroSala, numeroSala);
}
void Sala::setIdCine(char* idCine)
{
    strcpy(this->idCine, idCine);
}

void Sala::setNColumnasSala(char* nColumnasSala)
{
    strcpy(this->nColumnasSala, nColumnasSala);
}

void Sala::setNFilasSala(char* nFilasSala)
{
    strcpy(this->nFilasSala, nFilasSala);
}

char* Sala::getIdCine()
{
    return idCine;
}

char* Sala::getNumeroSala()
{
    return numeroSala;
}

char* Sala::getNColumnasSala()
{
    return nColumnasSala;
}

char* Sala::getNFilasSala()
{
    return nFilasSala;
}

