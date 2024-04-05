#ifndef CONFIGURACION_H
#define CONFIGURACION_H

// struct Configuracion {
//     char pathDB[];

// };

typedef struct
{
    char* ruta;
    int tamanyo;

} PathDB;


PathDB leerConfiguracion(char *fichero);

#endif
