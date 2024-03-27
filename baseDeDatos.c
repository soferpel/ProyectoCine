#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseDeDatos.h"
#include "menus.h"
#include "sqlite3.h"

void guardarUsuario()
{
    //Abrir la base de datos
    sqlite3 *db;
    int rc = sqlite3_open("cine.db", &db);

    //Insertar usuario
    sqlite3_stmt *stmt;
    char insertUsuario[] = "INSERT INTO USUARIO (NOMBRE, APELLIDO, NOM_USUARIO, CONTRASENA) VALUES (?, ?, ?, ?);";
    sqlite3_prepare_v2(db, insertUsuario, strlen(insertUsuario) + 1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, nombre, strlen(nombre) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, apellido, strlen(apellido) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, nombreUsuario, strlen(nombreUsuario) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, contrasena, strlen(contrasena) + 1, SQLITE_STATIC);

    sqlite3_step(stmt);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void validarUsuario()
{
    validacionUsuario = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select = "SELECT NOM_USUARIO, CONTRASENA FROM USUARIO;";
    rc = sqlite3_exec(db, sql_select, callbackUsuario, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    if (validacionUsuario == 1) {
        printf("El usuario es correcto\n");
    } else {
        printf("Usuario o contrasena incorrectos\n");
        menuBienvenida();
    }
    sqlite3_close(db);
}

int callbackUsuario(void *data, int argc, char **argv, char **col_names) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(nombreUsuario, argv[0]) == 0)
        {
            if (strcmp(contrasena, argv[1]) == 0)
            {
                validacionUsuario = 1;
                break;
            }
        }
    }

    return validacionUsuario;
}
