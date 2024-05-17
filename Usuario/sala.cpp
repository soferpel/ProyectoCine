#include "sala.h"

Sala::Sala(int numeroSala, int nColumnasSala, int nFilasSala, int idCine)
{
    this->idCine = idCine;
    this->numeroSala = numeroSala;
    this->nColumnasSala = nColumnasSala;
    this->nFilasSala = nFilasSala;
}

Sala::~Sala()
{
}

void Sala::setNumeroSala(int numeroSala)
{
    this->numeroSala = numeroSala;
}
void Sala::setIdCine(int idCine)
{
    this->idCine = idCine;
}

void Sala::setNColumnasSala(int nColumnasSala)
{
    this->nColumnasSala = nColumnasSala;
}

void Sala::setNFilasSala(int nFilasSala)
{
    this->nFilasSala = nFilasSala;
}

int Sala::getIdCine()
{
    return idCine;
}

int Sala::getNumeroSala()
{
    return numeroSala;
}

int Sala::getNColumnasSala()
{
    return nColumnasSala;
}

int Sala::getNFilasSala()
{
    return nFilasSala;
}

