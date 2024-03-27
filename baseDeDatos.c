#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseDeDatos.h"
#include "menus.h"
#include "sqlite3.h"

void crearTabla() {
    sqlite3 *db;
    char *error_message = 0;
    char *sentencia_sql0 = "CREATE TABLE IF NOT EXISTS USUARIO (ID_USUARIO INTEGER PRIMARY KEY, NOMBRE TEXT, RESPUESTA TEXT, CORREO TEXT, CONTRASENA TEXT);";
    char *sentencia_sql1 = "CREATE TABLE IF NOT EXISTS PELICULA (ID_PELICULA INTEGER PRIMARY KEY, ID_SALA INTEGER, TITULO TEXT, SINOPSIS TEXT, HORARIO TEXT);";
    char *sentencia_sql2 = "CREATE TABLE IF NOT EXISTS ACTOR (ID_ACTOR INTEGER PRIMARY KEY, ID_PELICULA, NOMBRE TEXT);";
    char *sentencia_sql3 = "CREATE TABLE IF NOT EXISTS CINE (ID_CINE INTEGER PRIMARY KEY, NOMBRE TEXT, DIRECCION TEXT, CIUDAD TEXT);";
    char *sentencia_sql4 = "CREATE TABLE IF NOT EXISTS ASIENTO (ID_ASIENTO INTEGER PRIMARY KEY, ID_SALA INTEGER,  FILA TEXT, NUMERO TEXT, FECHA TEXT);";
    char *sentencia_sql5 = "CREATE TABLE IF NOT EXISTS SALA (ID_SALA INTEGER PRIMARY KEY, ID_CINE INTEGER, NUMERO TEXT, NCOLUMNAS TEXT, NFILAS TEXT);";

    int rc = sqlite3_open("cine.db", &db);

    if (rc) {
        fprintf(stderr, "No se puede abrir la base de datos: %s\n", sqlite3_errmsg(db));
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
        fprintf(stderr, "Error al crear las tablas: %s\n", error_message);
        sqlite3_free(error_message);
    } else {
        printf("Tablas creadas correctamente\n");
    }

    // Cerrar la base de datos
    sqlite3_close(db);
}

void guardarUsuario()
{
    //Abrir la base de datos
    sqlite3 *db;
    int rc = sqlite3_open("cine.db", &db);

    //Insertar usuario
    sqlite3_stmt *stmt;
    char insertUsuario[] = "INSERT INTO USUARIO (NOMBRE, RESPUESTA, CORREO, CONTRASENA) VALUES (?, ?, ?, ?);";
    sqlite3_prepare_v2(db, insertUsuario, strlen(insertUsuario) + 1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, nombre, strlen(nombre) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, respuesta, strlen(respuesta) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, correo, strlen(correo) + 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, contrasena, strlen(contrasena) + 1, SQLITE_STATIC);

    sqlite3_step(stmt);
    autenticacionExitosa = 1;
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

    char *sql_select = "SELECT CORREO, CONTRASENA FROM USUARIO;";
    rc = sqlite3_exec(db, sql_select, callbackUsuario, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    if (validacionUsuario == 1) {
        printf("El usuario es correcto\n");
        autenticacionExitosa = 1;
    } else {
        printf("Usuario o contrasena incorrectos\n");
        menuBienvenida();
    }
    sqlite3_close(db);
}

int callbackUsuario(void *data, int argc, char **argv, char **col_names) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(correo, argv[0]) == 0)
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

void eliminarFila() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    char sql_delete[100];
    snprintf(sql_delete, sizeof(sql_delete), "DELETE FROM %s WHERE ID = '%s';", tabla, id);

    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al eliminar datos: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila eliminada correctamente de la tabla %s y id %s\n", tabla);
    }
    sqlite3_close(db);
}

void anadirAsiento() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    char sql_anadir[100];
    snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ASIENTO () VALUES ('%s', '%s', '%s');");

    rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al anadir asientos: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila anadida correctamente\n");
    }
    sqlite3_close(db);
}

void anadirCine() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    char sql_anadir[100];
    snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO CINE (NOMBRE, DIRECCION, CIUDAD) VALUES ('%s', '%s', '%s');", nombreCine, direccionCine, ciudadCine);

    rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al anadir el cine: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila anadida correctamente\n");
    }
    sqlite3_close(db);
}

void anadirSala() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    char sql_anadir[100];
    snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO SALA (ID_CINE, NUMERO, NCOLUMNAS, NFILAS) VALUES ('%i', '%s', '%s', '%s');", idCine, numeroSala, nColumnasSala, nFilasSala);

    rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al anadir LA SALA: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila anadida correctamente\n");
    }
    sqlite3_close(db);
}