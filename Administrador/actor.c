#include "configuracion.h"
#include "actor.h"
#include "pelicula.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

void validarActor(PathDB rutaDB, Logger *logger)
{
    validacionActor = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al abrir la base de datos: %s", sqlite3_errmsg(db));
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Actor = "SELECT ID_ACTOR FROM ACTOR;";
    rc = sqlite3_exec(db, sql_select_Actor, callbackActor, 0, &err_msg);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al realizar la consulta SELECT: %s", err_msg);
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    if (validacionActor == 1) {
        logger_log(logger, LOG_INFO, "El actor es correcto");
        printf("El actor es correcto\n");
    } else {
        logger_log(logger, LOG_ERROR, "El actor introducido no existe");
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

void modificarActor(PathDB rutaDB, Logger *logger)
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
                logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE ACTOR SET ID_ACTOR = '%i', ID_PELICULA = '%i', NOMBRE = '%s' WHERE ID_ACTOR = %i;", actor.idActorInt, pelicula.idPeliculaInt, actor.nombreActor, actor.idActorInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                logger_log(logger, LOG_ERROR, "Error al modificar el actor: %s", err_msg);
                fprintf(stderr, "Error al modificar el actor: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                logger_log(logger, LOG_INFO, "Actor modificado correctamente");
                printf("Actor modificado correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void anadirActor(PathDB rutaDB, Logger *logger)
{
    validarPelicula(rutaDB);
    if (validacionPelicula == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        if (rc != SQLITE_OK) {
            logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
            fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
            return;
        }

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ACTOR (ID_PELICULA, NOMBRE) VALUES ('%i', '%s');", pelicula.idPeliculaInt, actor.nombreActor);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            logger_log(logger, LOG_ERROR, "Error al anadir LA PELICULA: %s\n", err_msg);
            fprintf(stderr, "Error al anadir LA PELICULA: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            logger_log(logger, LOG_INFO, "Fila anadida correctamente");
            printf("Fila anadida correctamente\n");
        }

        sqlite3_close(db);
    }
}