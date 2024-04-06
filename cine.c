#include "cine.h"
#include <stdio.h>

void mostrarCinesPorProvincia(const Cine *cine, const char *provincia) {
    int i;
    for (i = 0; i < cine->num_provincias; i++) {
        if (strcmp(cine->provincias[i].nombre, provincia) == 0) {
            printf("Cines disponibles en %s:\n", provincia);
            int j;
            for (j = 0; j < cine->provincias[i].num_cines; j++) {
                printf("%d. %s, %s\n", j+1, cine->provincias[i].cines[j].nombre, cine->provincias[i].cines[j].direccion);
            }
            return;
        }
    }
    printf("Lo sentimos, no hay cines disponibles para la provincia especificada.\n");
}
