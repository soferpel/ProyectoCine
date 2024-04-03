#ifndef CONFIGURACION_H
#define CONFIGURACION_H

struct Configuracion {
    char pathDB[100];

};


void leerConfiguracion(const char *filename, struct Configuracion *configuracion);

#endif
