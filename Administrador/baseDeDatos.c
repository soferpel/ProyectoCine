#define MAX_DATA_SIZE 4096

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseDeDatos.h"
#include "logger.h"


void crearTabla(PathDB rutaDB, Logger *logger) {
    sqlite3 *db;
    char *error_message = 0;
    char *sentencia_sql0 = "CREATE TABLE IF NOT EXISTS USUARIO (ID_USUARIO INTEGER PRIMARY KEY, NOMBRE TEXT, RESPUESTA TEXT, CORREO TEXT, CONTRASENA TEXT);";
    char *sentencia_sql1 = "CREATE TABLE IF NOT EXISTS PELICULA (ID_PELICULA INTEGER PRIMARY KEY, ID_SALA INTEGER, TITULO TEXT, SINOPSIS TEXT, HORARIO TEXT);";
    char *sentencia_sql2 = "CREATE TABLE IF NOT EXISTS ACTOR (ID_ACTOR INTEGER PRIMARY KEY, ID_PELICULA, NOMBRE TEXT, FOREIGN KEY (ID_PELICULA) REFERENCES PELICULA(ID_PELICULA));";
    char *sentencia_sql3 = "CREATE TABLE IF NOT EXISTS CINE (ID_CINE INTEGER PRIMARY KEY, NOMBRE TEXT, DIRECCION TEXT, CIUDAD TEXT);";
    char *sentencia_sql5 = "CREATE TABLE IF NOT EXISTS SALA (ID_SALA INTEGER PRIMARY KEY, ID_CINE INTEGER, NUMERO INTEGER, NCOLUMNAS INTEGER, NFILAS INTEGER, FOREIGN KEY (ID_CINE) REFERENCES CINE(ID_CINE));";
    char *sentencia_sql4 = "CREATE TABLE IF NOT EXISTS ASIENTO (ID_ASIENTO INTEGER PRIMARY KEY, ID_SALA INTEGER, FILA INTEGER, NUMERO INTEGER, FECHA TEXT, FOREIGN KEY (ID_SALA) REFERENCES SALA(ID_SALA));";

    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc) {
        logger_log(logger, LOG_ERROR, "No se puede abrir la base de datos: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sentencia_sql0, 0, 0, &error_message);
    rc = sqlite3_exec(db, sentencia_sql1, 0, 0, &error_message);
    rc = sqlite3_exec(db, sentencia_sql2, 0, 0, &error_message);
    rc = sqlite3_exec(db, sentencia_sql3, 0, 0, &error_message);
    rc = sqlite3_exec(db, sentencia_sql4, 0, 0, &error_message);
    rc = sqlite3_exec(db, sentencia_sql5, 0, 0, &error_message);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al crear las tablas: %s", error_message);
        sqlite3_free(error_message);
    } else {
        logger_log(logger, LOG_INFO, "Tablas creadas correctamente");
    }

    // Cerrar la base de datos
    sqlite3_close(db);
}

void borrarTablas(PathDB rutaDB, Logger *logger)
{
    sqlite3 *db;
    char *error_message = 0;
    char *sql_drop = "DROP TABLE IF EXISTS USUARIO;";
    char *sql_drop1 = "DROP TABLE IF EXISTS PELICULA;";
    char *sql_drop2 = "DROP TABLE IF EXISTS ACTOR;";
    char *sql_drop3 = "DROP TABLE IF EXISTS CINE;";
    char *sql_drop4 = "DROP TABLE IF EXISTS ASIENTO;";
    char *sql_drop5 = "DROP TABLE IF EXISTS SALA;";
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc) {
        logger_log(logger, LOG_ERROR, "No se puede abrir la base de datos: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, sql_drop, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop1, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop2, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop3, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop4, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop5, 0, 0, &error_message);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al eliminar las tablas: %s", error_message);
        sqlite3_free(error_message);
    } else {
        logger_log(logger, LOG_INFO, "Tablas eliminadas correctamente");
    }
}

void eliminarFila(PathDB rutaDB, Logger *logger) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    char sql_delete[100];
    snprintf(sql_delete, sizeof(sql_delete), "DELETE FROM %s WHERE ID_%s = '%s';", tablaEliminar, tablaEliminar, idEliminar);

    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al eliminar datos: %s", err_msg);
        sqlite3_free(err_msg);
    } else {
        logger_log(logger, LOG_INFO, "Fila eliminada correctamente");
    }
    sqlite3_close(db);
}

int visualizarDatos(PathDB rutaDB, Logger *logger, char *buffer) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Cannot open database: %s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return rc;
    }

    char sql_query[100];
    snprintf(sql_query, sizeof(sql_query), "SELECT * FROM %s;", tablaVisualizar);

    rc = sqlite3_exec(db, sql_query, callbackVisualizarDatos, buffer, &err_msg);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "Error al visualizar datos: %s", err_msg);
        sqlite3_free(err_msg);
    } else {
        logger_log(logger, LOG_INFO, "Visualizacion exitosa");
    }

    sqlite3_close(db);
    return rc;
}

int callbackVisualizarDatos(void *data, int argc, char **argv, char **azColName) {
    char *buffer = (char *)data;
    for (int i = 0; i < argc; i++) {
        strcat(buffer, azColName[i]);
        strcat(buffer, " = ");
        strcat(buffer, argv[i] ? argv[i] : "NULL");
        strcat(buffer, "\n");
    }
    strcat(buffer, "\n");
    return 0;
}
