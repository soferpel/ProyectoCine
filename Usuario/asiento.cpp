#include "asiento.h"
#include <string.h>

Asiento::Asiento(char* filaAsiento, char* numeroAsiento, char* fechaAsiento, char* idSala)
{
    this->filaAsiento = new char[strlen(filaAsiento) + 1 ];
    strcpy(this->filaAsiento, filaAsiento);
    this->numeroAsiento = new char[strlen(numeroAsiento) + 1 ];
    strcpy(this->numeroAsiento, numeroAsiento);
    this->idSala = new char[strlen(idSala) + 1 ];
    strcpy(this->idSala, idSala);
    this->fechaAsiento = new char[strlen(fechaAsiento) + 1 ];
    strcpy(this->fechaAsiento, fechaAsiento);
}

Asiento::~Asiento()
{
    delete[] this->fechaAsiento;
    delete[] this->filaAsiento;
    delete[] this->numeroAsiento;
    delete[] this->idSala;
}

void Asiento::setFilaAsiento(char* filaAsiento)
{
    this->filaAsiento = filaAsiento;
}

void Asiento::setNumeroAsiento(char* numeroAsiento)
{
    this->numeroAsiento = numeroAsiento;
}

void Asiento::setFechaAsiento(char* fechaAsiento)
{
    strcpy(this->fechaAsiento, fechaAsiento);
}

void Asiento::setIdSala(char* idSala)
{
    this->idSala = idSala;
}

char* Asiento::getIdAsiento()
{
    return this->idAsiento;
}

char* Asiento::getFilaAsiento()
{
    return this->filaAsiento;
}  

char* Asiento::getNumeroAsiento()
{
    return this->numeroAsiento;
}

char* Asiento::getFechaAsiento()
{
    return this->fechaAsiento;
}

char* Asiento::getIdSala()
{
    return this->idSala;
}

