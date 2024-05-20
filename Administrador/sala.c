#include "configuracion.h"
#include "sala.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

void anadirSala(PathDB rutaDB, Logger *logger) {
    validarCine(rutaDB, logger);
    if (validacionCine == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO SALA (ID_CINE, NUMERO, NCOLUMNAS, NFILAS) VALUES ('%i', '%i', '%i', '%i');", cine.idCineInt, sala.numeroSalaInt, sala.nColumnasSalaInt, sala.nFilasSalaInt);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            logger_log(logger, LOG_ERROR, "Error al anadir LA SALA: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            logger_log(logger, LOG_INFO, "Fila anadida correctamente");
        }
        sqlite3_close(db);
    }
}

void modificarSala(PathDB rutaDB, Logger *logger)
{
    validarSala(rutaDB, logger);
    if(validacionSala == 1)
    {
        validarCine(rutaDB, logger);
        if(validacionCine == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE SALA SET ID_SALA = '%i', ID_CINE = '%i', NUMERO = '%i', NCOLUMNAS = '%i', NFILAS = '%i WHERE ID_SALA = %i;", sala.idSalaInt, cine.idCineInt, sala.numeroSalaInt, sala.nColumnasSalaInt, sala.nFilasSalaInt, sala.idSalaInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                logger_log(logger, LOG_ERROR, "Error al modificar la sala: %s", err_msg);
                sqlite3_free(err_msg);
            } else {
                logger_log(logger, LOG_INFO, "Sala modificada correctamente");
            }

            sqlite3_close(db);
        }
    }
}

void validarSala(PathDB rutaDB, Logger *logger)
{
    validacionSala = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Sala = "SELECT ID_SALA FROM SALA;";
    rc = sqlite3_exec(db, sql_select_Sala, callbackSala, 0, &err_msg);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al realizar la consulta SELECT: %s", err_msg);
        sqlite3_free(err_msg);
    }
    if (validacionSala == 1) {
        logger_log(logger, LOG_INFO, "La sala es correcta");
    } else {
        logger_log(logger, LOG_ERROR, "La sala introducida no existe");
    }
    sqlite3_close(db);
}

int callbackSala(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idSala = atoi(argv[i]);
        if (sala.idSalaInt == idSala)
        {
            validacionSala = 1;
            break;
        }
    }

    return validacionCine;
}