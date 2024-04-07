#include "configuracion.h"
#include "actor.h"
#include "pelicula.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void validarActor(PathDB rutaDB)
{
    validacionActor = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Actor = "SELECT ID_ACTOR FROM ACTOR;";
    rc = sqlite3_exec(db, sql_select_Actor, callbackActor, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    if (validacionActor == 1) {
        printf("El actor es correcto\n");
    } else {
        printf("El actor introducido no existe\n");
    }
    sqlite3_close(db);
}

int callbackActor(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idActor = atoi(argv[i]);
        if (actor.idActorInt == idActor)
        {
            validacionActor = 1;
            break;
        }
    }

    return validacionPelicula;
}

void modificarActor(PathDB rutaDB)
{
    validarActor(rutaDB);
    if(validacionActor == 1)
    {
        validarPelicula(rutaDB);
        if(validacionPelicula == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE ACTOR SET ID_ACTOR = '%i', ID_PELICULA = '%i', NOMBRE = '%s' WHERE ID_ACTOR = %i;", actor.idActorInt, pelicula.idPeliculaInt, actor.nombreActor, actor.idActorInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el actor: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Actor modificado correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void anadirActor(PathDB rutaDB)
{
    validarPelicula(rutaDB);
    if (validacionPelicula == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ACTOR (ID_PELICULA, NOMBRE) VALUES ('%i', '%s');", pelicula.idPeliculaInt, actor.nombreActor);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al anadir LA PELICULA: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadida correctamente\n");
        }

        sqlite3_close(db);
    }
}