#include "configuracion.h"
#include "sala.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void anadirSala(PathDB rutaDB) {
    validarCine(rutaDB);
    if (validacionCine == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO SALA (ID_CINE, NUMERO, NCOLUMNAS, NFILAS) VALUES ('%i', '%i', '%i', '%i');", idCineInt, numeroSalaInt, nColumnasSalaInt, nFilasSalaInt);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al anadir LA SALA: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadida correctamente\n");
        }
        sqlite3_close(db);
    }
}

void modificarSala(PathDB rutaDB)
{
    validarSala(rutaDB);
    if(validacionSala == 1)
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
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE SALA SET ID_SALA = '%i', ID_CINE = '%i', NUMERO = '%i', NCOLUMNAS = '%i', NFILAS = '%i WHERE ID_SALA = %i;", idSalaInt, idCineInt, numeroSalaInt, nColumnasSalaInt, nFilasSalaInt, idSalaInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar la sala: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Sala modificada correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void validarSala(PathDB rutaDB)
{
    validacionSala = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Sala = "SELECT ID_SALA FROM SALA;";
    rc = sqlite3_exec(db, sql_select_Sala, callbackSala, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionSala == 1) {
        printf("La sala es correcta\n");
    } else {
        printf("La sala introducida no existe\n");
    }
    sqlite3_close(db);
}

int callbackSala(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idSala = atoi(argv[i]);
        if (idSalaInt == idSala)
        {
            validacionSala = 1;
            break;
        }
    }

    return validacionCine;
}