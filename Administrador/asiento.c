#include "configuracion.h"
#include "asiento.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

void anadirAsiento(PathDB rutaDB, Logger *logger) {
    validarSala(rutaDB, logger);
    if (validacionSala == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ASIENTO (ID_SALA, FILA, NUMERO, FECHA) VALUES ('%i', '%i', '%i', '%s');", sala.idSalaInt, asiento.filaAsientoInt, asiento.numeroAsientoInt, asiento.fechaAsiento);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);
        
        if (rc != SQLITE_OK) {
            logger_log(logger, LOG_ERROR, "Error al añadir asientos: %s", err_msg);
            sqlite3_free(err_msg);
        } else {
            logger_log(logger, LOG_INFO, "Fila anadida correctamente");
        }
        
        sqlite3_close(db);
    }
}

void modificarAsiento(PathDB rutaDB, Logger *logger)
{
    validarAsiento(rutaDB, logger);
    if(validacionAsiento == 1)
    {
        validarSala(rutaDB, logger);
        if(validacionSala == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE ASIENTO SET ID_ASIENTO = '%i', ID_SALA = '%i', FILA = '%i', NUMERO = '%i', FECHA = '%s WHERE ID_ASIENTO = %i;", asiento.idAsientoInt, sala.idSalaInt, asiento.filaAsientoInt, asiento.numeroAsientoInt, asiento.fechaAsiento, asiento.idAsientoInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                logger_log(logger, LOG_ERROR, "Error al modificar el asiento: %s", err_msg);
                sqlite3_free(err_msg);
            } else {
                logger_log(logger, LOG_INFO, "Asiento modificado correctamente");
            }

            sqlite3_close(db);
        }
    }
}

void validarAsiento(PathDB rutaDB, Logger *logger)
{
    validacionAsiento = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Actor = "SELECT ID_ASIENTO FROM ASIENTO;";
    rc = sqlite3_exec(db, sql_select_Actor, callbackAsiento, 0, &err_msg);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al realizar la consulta SELECT: %s", err_msg);
        sqlite3_free(err_msg);
    }
    if (validacionAsiento == 1) {
        logger_log(logger, LOG_INFO, "El asiento es correcto");
    } else {
        logger_log(logger, LOG_ERROR, "El asiento introducido no existe");
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