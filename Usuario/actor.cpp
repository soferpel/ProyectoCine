#include "actor.h"

Actor::Actor(char* nombreActor, int idPelicula)
{
    this->nombreActor = new char[strlen(nombreActor) + 1];
    strcpy(this->nombreActor, nombreActor);
    this->idPelicula = idPelicula;
}

Actor::~Actor()
{
    delete[] this->nombreActor;
}

void Actor::setNombreActor(char* nombreActor)
{
    strcpy(this->nombreActor, nombreActor);
}

void Actor::setIdPelicula(int idPelicula)
{
    this->idPelicula = idPelicula;
}

int Actor::getIdActor()
{
    return this->idActor;
}

char* Actor::getNombreActor()
{
    return this->nombreActor;
}

int Actor::getIdPelicula()
{
    return this->idPelicula;
}
