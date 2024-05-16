#ifndef SALA_H
#define SALA_H

class Sala{
    
    private:
        int idSala;
        int numeroSala;
        int nColumnasSala;
        int nFilasSala;
    public:
        Sala(int numeroSala, int nColumnasSala, int nFilasSala);
        ~Sala();

        void setNumeroSala(int numeroSala);
        void setNColumnasSala(int nColumnasSala);
        void setNFilasSala(int nFilasSala);
        int getIdSala();
        int getNumeroSala();
        int getNColumnasSala();
        int getNFilasSala();

};

#endif