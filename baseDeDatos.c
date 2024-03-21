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
    sqlite3_open("cine.db", &db);

    //Insertar usuario
    sqlite3_stmt *stmt;
    char insertUsuario[] = "INSERT INTO USUARIO (NOMBRE, APELLIDO, NOM_USUARIO, CONTRASENA) VALUES (?, ?, ?, ?)";
    sqlite3_prepare_v2(db, insertUsuario, strlen(insertUsuario) + 1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, nombre, strlen(nombre) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, apellido, strlen(apellido) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, nombreUsuario, strlen(nombreUsuario) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, contrasena, strlen(contrasena) + 1, SQLITE_STATIC);

    sqlite3_step(stmt);


    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
