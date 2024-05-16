#include "sala.h"

Sala::Sala(int numeroSala, int nColumnasSala, int nFilasSala)
{
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

void Sala::setNColumnasSala(int nColumnasSala)
{
    this->nColumnasSala = nColumnasSala;
}

void Sala::setNFilasSala(int nFilasSala)
{
    this->nFilasSala = nFilasSala;
}

int Sala::getIdSala()
{
    return idSala;
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

