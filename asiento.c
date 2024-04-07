#include "configuracion.h"
#include "asiento.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void anadirAsiento(PathDB rutaDB) {
    validarSala(rutaDB);
    if (validacionSala == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ASIENTO (ID_SALA, FILA, NUMERO, FECHA) VALUES ('%i', '%i', '%i', '%s');", idSalaInt, asiento.filaAsientoInt, asiento.numeroAsientoInt, asiento.fechaAsiento);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);
        
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al añadir asientos: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadida correctamente\n");
        }
        
        sqlite3_close(db);
    }
}

void modificarAsiento(PathDB rutaDB)
{
    validarAsiento(rutaDB);
    if(validacionAsiento == 1)
    {
        validarSala(rutaDB);
        if(validacionSala == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE ASIENTO SET ID_ASIENTO = '%i', ID_SALA = '%i', FILA = '%i', NUMERO = '%i', FECHA = '%s WHERE ID_ASIENTO = %i;", asiento.idAsientoInt, idSalaInt, asiento.filaAsientoInt, asiento.numeroAsientoInt, asiento.fechaAsiento, asiento.idAsientoInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el asiento: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Asiento modificado correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void validarAsiento(PathDB rutaDB)
{
    validacionAsiento = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Actor = "SELECT ID_ASIENTO FROM ASIENTO;";
    rc = sqlite3_exec(db, sql_select_Actor, callbackAsiento, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionAsiento == 1) {
        printf("El asiento es correcto\n");
    } else {
        printf("El asiento introducido no existe\n");
    }
    sqlite3_close(db);
}

int callbackAsiento(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idAsiento = atoi(argv[i]);
        if (asiento.idAsientoInt == idAsiento)
        {
            validacionAsiento = 1;
            break;
        }
    }

    return validacionAsiento;
}