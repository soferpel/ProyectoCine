#ifndef PELICULA_H
#define PELICULA_H

class Pelicula
{
    private:
        int idPelicula;
        char titulo[20];
        char sinopsis[100];
        char horario[20];
        int idCine;

    public:
        Pelicula(char titulo[20], char sinopsis[100], char horario[20], int idCine);
        ~Pelicula();

        void setTitulo(char titulo[20]);
        void setSinopsis(char sinopsis[100]);
        void setHorario(char horario[20]);
        void setIdCine(int idCine);
        int getIdPelicula();
        char* getTitulo();
        char* getSinopsis();
        char* getHorario();
        int getIdCine();

};

#endif