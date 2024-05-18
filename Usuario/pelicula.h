#ifndef PELICULA_H
#define PELICULA_H

class Pelicula
{
    private:
        char* idPelicula;
        char* titulo;
        char* sinopsis;
        char* horario;
        char* idSala;

    public:
        Pelicula(char* titulo, char* sinopsis, char* horario, char* idSala);
        ~Pelicula();

        void setTitulo(char* titulo);
        void setSinopsis(char* sinopsis);
        void setHorario(char* horario);
        void setIdSala(char* idSala);
        char* getIdPelicula();
        char* getTitulo();
        char* getSinopsis();
        char* getHorario();
        char* getIdSala();

};

#endif