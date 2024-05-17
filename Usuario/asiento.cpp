#include "asiento.h"

Asiento::Asiento(int filaAsiento, int numeroAsiento, char* fechaAsiento, int idSala)
{
    this->filaAsiento = filaAsiento;
    this->numeroAsiento = numeroAsiento;
    this->idSala = idSala;
    this->fechaAsiento = new char[strlen(fechaAsiento) + 1 ];
    strcpy(this->fechaAsiento, fechaAsiento);
}

Asiento::~Asiento()
{
    delete[] this->fechaAsiento;
}

void Asiento::setFilaAsiento(int filaAsiento)
{
    this->filaAsiento = filaAsiento;
}

void Asiento::setNumeroAsiento(int numeroAsiento)
{
    this->numeroAsiento = numeroAsiento;
}

void Asiento::setFechaAsiento(char* fechaAsiento)
{
    strcpy(this->fechaAsiento, fechaAsiento);
}

void Asiento::setIdSala(int idSala)
{
    this->idSala = idSala;
}

int Asiento::getIdAsiento()
{
    return this->idAsiento;
}

int Asiento::getFilaAsiento()
{
    return this->filaAsiento;
}  

int Asiento::getNumeroAsiento()
{
    return this->numeroAsiento;
}

char* Asiento::getFechaAsiento()
{
    return this->fechaAsiento;
}

int Asiento::getIdSala()
{
    return this->idSala;
}

