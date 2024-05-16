#ifndef ACTOR_H
#define ACTOR_H

class Actor
{
    private:
        int idActorInt;
        char nombreActor[20];
        int idPelicula;
    public:
        Actor(char nombreActor[20], int idPelicula);
        ~Actor();

        void setNombreActor(char nombreActor[20]);
        void setIdPelicula(int idPelicula);
        int getIdActor();
        char* getNombreActor();
        int getIdPelicula();
};

#endif