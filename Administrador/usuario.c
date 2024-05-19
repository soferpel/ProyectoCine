#include "configuracion.h"
#include "usuario.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

void guardarUsuario(PathDB rutaDB, Logger *logger)
{
    //TODO: si el usuario ya existe, notificar al usuario

    //Abrir la base de datos
    sqlite3 *db;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    //Insertar usuario
    sqlite3_stmt *stmt;
    char insertUsuario[] = "INSERT INTO USUARIO (NOMBRE, RESPUESTA, CORREO, CONTRASENA) VALUES (?, ?, ?, ?);";
    sqlite3_prepare_v2(db, insertUsuario, strlen(insertUsuario) + 1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, usuario.nombre, strlen(usuario.nombre) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, usuario.respuesta, strlen(usuario.respuesta) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, usuario.correo, strlen(usuario.correo) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, usuario.contrasena, strlen(usuario.contrasena) + 1, SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    autenticacionExitosa = 1;
}

void modificarUsuario(PathDB rutaDB, Logger *logger)
{
    validarUsuario(rutaDB, logger);
    if(validacionUsuario == 1)
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
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE USUARIO SET ID_USUARIO = '%i', NOMBRE = '%s', RESPUESTA = '%s', CORREO = '%s', CONTRASENA = '%s WHERE ID_USUARIO = %i;", usuario.idUsuarioInt, usuario.nombre, usuario.respuesta, usuario.correo, usuario.contrasena, usuario.idUsuarioInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el usuario: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Usuario modificado correctamente\n");
            }

            sqlite3_close(db);
    }
}

void validarUsuario(PathDB rutaDB, Logger *logger)
{
    validacionUsuario = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        logger_log(logger, LOG_ERROR, "No se pudo abrir la base de datos: %s", sqlite3_errmsg(db));
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Usuario = "SELECT CORREO, CONTRASENA FROM USUARIO;";
    rc = sqlite3_exec(db, sql_select_Usuario, callbackUsuario, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    if (validacionUsuario == 1) {
        printf("El usuario es correcto\n");
        autenticacionExitosa = 1;
    } else {
        printf("Usuario o contrasena incorrectos\n");
    }
    sqlite3_close(db);
}

int callbackUsuario(void *data, int argc, char **argv, char **col_names) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(usuario.correo, argv[0]) == 0)
        {
            if (strcmp(usuario.contrasena, argv[1]) == 0)
            {
                validacionUsuario = 1;
                break;
            }
        }
    }

    return validacionUsuario;
}