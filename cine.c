#include "configuracion.h"
#include "cine.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void anadirCine(PathDB rutaDB) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    char sql_anadir[100];
    snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO CINE (NOMBRE, DIRECCION, CIUDAD) VALUES ('%s', '%s', '%s');", cine.nombreCine, cine.direccionCine, cine.ciudadCine);

    rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al anadir el cine: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila anadida correctamente\n");
    }
    sqlite3_close(db);
}

void modificarCine(PathDB rutaDB)
{
    validarCine(rutaDB);
    if(validacionCine == 1)
    {
        sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE CINE SET ID_CINE = '%i', NOMBRE = '%s', DIRECCION = '%s', CIUDAD = '%s' WHERE ID_CINE = %i;", cine.idCineInt, cine.nombreCine, cine.direccionCine, cine.ciudadCine, cine.idCineInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el cine: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Cine modificado correctamente\n");
            }

            sqlite3_close(db);
    }
}

void validarCine(PathDB rutaDB)
{
    validacionCine = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Cine = "SELECT ID_CINE FROM CINE;";
    rc = sqlite3_exec(db, sql_select_Cine, callbackCine, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionCine == 1) {
        printf("El cine es correcto\n");
    } else {
        printf("El cine introducido no existe\n");
    }
    sqlite3_close(db);
}

int callbackCine(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idCine = atoi(argv[i]);
        if (cine.idCineInt == idCine)
        {
            validacionCine = 1;
            break;
        }
    }

    return validacionCine;
}

