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

void validarUsuario(char nomUsuario[], char contrasenya[])
{
    //Abrir la base de datos
    sqlite3 *db;
    sqlite3_open("cine.db", &db);

    //Seleccionar los usarios registrados
    sqlite3_stmt *stmt2;
    char selectUsuarios[] = "SELECT NOM_USUARIO, CONTRASENA FROM USUARIO;";
    sqlite3_prepare_v2(db, selectUsuarios, strlen(selectUsuarios) + 1, &stmt2, NULL);
    
    // sqlite3_bind_text(stmt2, 1, nomUsuario, strlen(nomUsuario) + 1, SQLITE_STATIC);
    // sqlite3_bind_text(stmt2, 2, contrasenya, strlen(contrasenya) + 1, SQLITE_STATIC);
    
    sqlite3_step(stmt2);

    //Comprobar si el usuario y la contrasena son correctos
    while(sqlite3_step(stmt2) == SQLITE_ROW)
    {
        printf("Usuario: %s\n", sqlite3_column_text(stmt2, 1));
        if((char*)sqlite3_column_text(stmt2, 3) == nomUsuario && (char*)sqlite3_column_text(stmt2, 4) == contrasenya)
        {
            autenticacionExitosa = 1;
        } else
        {
            printf("Usuario o contrasena incorrectos o usuario no registrado\n");
            menuInicioSesion();
        }
    }

    sqlite3_finalize(stmt2);
    sqlite3_close(db);
}
