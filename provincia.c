#include "provincia.h"
#include <string.h>

void inicializarProvincias(Provincia provincias[MAX_PROVINCIAS]) {
    // Cines en Madrid
    strcpy(provincias[0].nombre, "Madrid");
    strcpy(provincias[0].cines[0].nombre, "Cine Madrid 1");
    strcpy(provincias[0].cines[0].direccion, "Dirección Madrid 1");
    strcpy(provincias[0].cines[1].nombre, "Cine Madrid 2");
    strcpy(provincias[0].cines[1].direccion, "Dirección Madrid 2");
    provincias[0].num_cines = 2;

    // Cines en Barcelona
    strcpy(provincias[1].nombre, "Barcelona");
    strcpy(provincias[1].cines[0].nombre, "Cine Barcelona 1");
    strcpy(provincias[1].cines[0].direccion, "Dirección Barcelona 1");
    strcpy(provincias[1].cines[1].nombre, "Cine Barcelona 2");
    strcpy(provincias[1].cines[1].direccion, "Dirección Barcelona 2");
    provincias[1].num_cines = 2;

    // Cines en Valencia
    strcpy(provincias[2].nombre, "Valencia");
    strcpy(provincias[2].cines[0].nombre, "Cine Valencia 1");
    strcpy(provincias[2].cines[0].direccion, "Dirección Valencia 1");
    provincias[2].num_cines = 1;
}
