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
    char *sentencia_sql2 = "CREATE TABLE IF NOT EXISTS ACTOR (ID_ACTOR INTEGER PRIMARY KEY, ID_PELICLA, NOMBRE TEXT);";
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

void borrarTablas()
{
    sqlite3 *db;
    char *error_message = 0;
    char *sql_drop = "DROP TABLE IF EXISTS USUARIO;";
    char *sql_drop1 = "DROP TABLE IF EXISTS PELICULA;";
    char *sql_drop2 = "DROP TABLE IF EXISTS ACTOR;";
    char *sql_drop3 = "DROP TABLE IF EXISTS CINE;";
    char *sql_drop4 = "DROP TABLE IF EXISTS ASIENTO;";
    char *sql_drop5 = "DROP TABLE IF EXISTS SALA;";
    int rc = sqlite3_open("cine.db", &db);
    rc = sqlite3_exec(db, sql_drop, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop1, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop2, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop3, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop4, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop5, 0, 0, &error_message);
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
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    autenticacionExitosa = 1;
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

void validarCine()
{
    validacionCine = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Cine = "SELECT ID_CINE FROM CINE;";
    rc = sqlite3_exec(db, sql_select_Cine, callbackCine, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    if (validacionCine == 1) {
        printf("El cine es correcto\n");
    } else {
        printf("El cine introducido no existe\n");
    }
    sqlite3_close(db);
}

int callbackCine(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idCine = atoi(argv[i]);
        if (idCineInt == idCine)
        {
            validacionCine = 1;
            break;
        }
    }

    return validacionCine;
}

void validarSala()
{
    validacionSala = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Cine = "SELECT ID_SALA FROM SALA;";
    rc = sqlite3_exec(db, sql_select_Cine, callbackSala, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    if (validacionSala == 1) {
        printf("La sala es correcta\n");
    } else {
        printf("La sala introducido no existe\n");
    }
    sqlite3_close(db);
}

int callbackSala(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idSala = atoi(argv[i]);
        if (idSalaIntAsiento == idSala)
        {
            validacionSala = 1;
            break;
        }
    }

    return validacionCine;
}

void eliminarFila() {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    char sql_delete[100];
    snprintf(sql_delete, sizeof(sql_delete), "DELETE FROM %s WHERE ID_%s = '%s';", tabla, tabla, id);

    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al eliminar datos: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila eliminada correctamente");
    }
    sqlite3_close(db);
}

void anadirAsiento() {
    validarSala();
    if (validacionSala == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open("cine.db", &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ASIENTO (ID_SALA, FILA, NUMERO, FECHA) VALUES ('%i', '%s', '%s', '%s');", idSalaIntAsiento, filaAsiento, numeroAsiento, fechaAsiento);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);
        
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al añadir asientos: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadida correctamente\n");
        }
        
        sqlite3_close(db);
    }
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
    validarCine();
    if (validacionCine == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open("cine.db", &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO SALA (ID_CINE, NUMERO, NCOLUMNAS, NFILAS) VALUES ('%i', '%s', '%s', '%s');", idCineInt, numeroSala, nColumnasSala, nFilasSala);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al anadir LA SALA: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadida correctamente\n");
        }
        sqlite3_close(db);
    }
}

void anadirPelicula()
{
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("cine.db", &db);

    char sql_anadir[100];
    snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO PELICULA (ID_SALA, TITULO, SINOPSIS, HORARIO) VALUES ('%i', '%s', '%s', '%s');", idSalaIntPelicula, titulo, sinopsis, horario);

    rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al anadir LA PELICULA: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila anadida correctamente\n");
    }

    sqlite3_close(db);

}