#ifndef PELICULA_H
#define PELICULA_H

class Pelicula
{
    private:
        int idPelicula;
        char* titulo;
        char* sinopsis;
        char* horario;
        int idSala;

    public:
        Pelicula(char* titulo, char* sinopsis, char* horario, int idSala);
        ~Pelicula();

        void setTitulo(char* titulo);
        void setSinopsis(char* sinopsis);
        void setHorario(char* horario);
        void setIdSala(int idSala);
        int getIdPelicula();
        char* getTitulo();
        char* getSinopsis();
        char* getHorario();
        int getIdSala();

};

#endif