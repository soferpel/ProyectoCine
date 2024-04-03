#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion.h" 

void leerConfiguracion(const char *filename, struct Configuracion *configuracion) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        char key[100];
        char value[100];
        if (sscanf(line, "%[^=]= %[^\n]", key, value) == 2) {
            if (strcmp(key, "pathDB") == 0) {
                strcpy(configuracion->pathDB, value);
            }
        }
    }

    fclose(file);
}

