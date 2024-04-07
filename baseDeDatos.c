#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baseDeDatos.h"
#include "sqlite3.h"

void crearTabla(PathDB rutaDB) {
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

void borrarTablas(PathDB rutaDB)
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
    rc = sqlite3_exec(db, sql_drop, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop1, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop2, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop3, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop4, 0, 0, &error_message);
    rc = sqlite3_exec(db, sql_drop5, 0, 0, &error_message);
}

void guardarUsuario(PathDB rutaDB)
{
    //TODO: si el usuario ya existe, notificar al usuario

    //Abrir la base de datos
    sqlite3 *db;
    int rc = sqlite3_open(rutaDB.ruta, &db);

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

void validarUsuario(PathDB rutaDB)
{
    validacionUsuario = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Usuario = "SELECT CORREO, CONTRASENA FROM USUARIO;";
    rc = sqlite3_exec(db, sql_select_Usuario, callbackUsuario, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }

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

void validarCine(PathDB rutaDB)
{
    validacionCine = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Cine = "SELECT ID_CINE FROM CINE;";
    rc = sqlite3_exec(db, sql_select_Cine, callbackCine, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
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

void validarSala(PathDB rutaDB)
{
    validacionSala = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Sala = "SELECT ID_SALA FROM SALA;";
    rc = sqlite3_exec(db, sql_select_Sala, callbackSala, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionSala == 1) {
        printf("La sala es correcta\n");
    } else {
        printf("La sala introducida no existe\n");
    }
    sqlite3_close(db);
}

int callbackSala(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idSala = atoi(argv[i]);
        if (idSalaInt == idSala)
        {
            validacionSala = 1;
            break;
        }
    }

    return validacionCine;
}

void validarPelicula(PathDB rutaDB)
{
    validacionPelicula = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Pelicula = "SELECT ID_PELICULA FROM PELICULA;";
    rc = sqlite3_exec(db, sql_select_Pelicula, callbackPelicula, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionPelicula == 1) {
        printf("La pelicula es correcta\n");
    } else {
        printf("La pelicula introducida no existe\n");
    }
    sqlite3_close(db);
}

int callbackPelicula(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idPelicula = atoi(argv[i]);
        if (idPeliculaInt == idPelicula)
        {
            validacionPelicula = 1;
            break;
        }
    }

    return validacionPelicula;
}

void validarActor(PathDB rutaDB)
{
    validacionActor = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Actor = "SELECT ID_ACTOR FROM ACTOR;";
    rc = sqlite3_exec(db, sql_select_Actor, callbackActor, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionActor == 1) {
        printf("El actor es correcto\n");
    } else {
        printf("El actor introducido no existe\n");
    }
    sqlite3_close(db);
}

int callbackActor(void *data, int argc, char **argv, char **col_names)
{
    for (int i = 0; i < argc; i++) {
        int idActor = atoi(argv[i]);
        if (idActorInt == idActor)
        {
            validacionActor = 1;
            break;
        }
    }

    return validacionPelicula;
}

void validarAsiento(PathDB rutaDB)
{
    validacionAsiento = 0;
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql_select_Actor = "SELECT ID_ASIENTO FROM ASIENTO;";
    rc = sqlite3_exec(db, sql_select_Actor, callbackActor, 0, &err_msg);

    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    // }
    if (validacionActor == 1) {
        printf("El asiento es correcto\n");
    } else {
        printf("El asiento introducido no existe\n");
    }
    sqlite3_close(db);
}



void eliminarFila(PathDB rutaDB) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

    char sql_delete[100];
    snprintf(sql_delete, sizeof(sql_delete), "DELETE FROM %s WHERE ID_%s = '%s';", tablaEliminar, tablaEliminar, idEliminar);

    rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al eliminar datos: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Fila eliminada correctamente");
    }
    sqlite3_close(db);
}

void anadirAsiento(PathDB rutaDB) {
    validarSala(rutaDB);
    if (validacionSala == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ASIENTO (ID_SALA, FILA, NUMERO, FECHA) VALUES ('%i', '%i', '%i', '%s');", idSalaInt, filaAsientoInt, numeroAsientoInt, fechaAsiento);

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

void anadirCine(PathDB rutaDB) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open(rutaDB.ruta, &db);

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

void anadirSala(PathDB rutaDB) {
    validarCine(rutaDB);
    if (validacionCine == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO SALA (ID_CINE, NUMERO, NCOLUMNAS, NFILAS) VALUES ('%i', '%i', '%i', '%i');", idCineInt, numeroSalaInt, nColumnasSalaInt, nFilasSalaInt);

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

void anadirPelicula(PathDB rutaDB)
{
    validarSala(rutaDB);
    if (validacionSala == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);
        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO PELICULA (ID_SALA, TITULO, SINOPSIS, HORARIO) VALUES ('%i', '%s', '%s', '%s');", idSalaInt, titulo, sinopsis, horario);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al anadir la pelicula: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadir correctamente\n");
        }

        sqlite3_close(db);
    }
}

void anadirActor(PathDB rutaDB)
{
    validarPelicula(rutaDB);
    if (validacionPelicula == 1)
    {
        sqlite3 *db;
        char *err_msg = 0;
        int rc = sqlite3_open(rutaDB.ruta, &db);

        char sql_anadir[100];
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO ACTOR (ID_PELICULA, NOMBRE) VALUES ('%i', '%s');", idPeliculaInt, nombreActor);

        rc = sqlite3_exec(db, sql_anadir, 0, 0, &err_msg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "Error al anadir LA PELICULA: %s\n", err_msg);
            sqlite3_free(err_msg);
        } else {
            printf("Fila anadida correctamente\n");
        }

        sqlite3_close(db);
    }
}

void modificarPelicula(PathDB rutaDB) {
    validarPelicula(rutaDB);
    if (validacionPelicula == 1)
    {
        validarSala(rutaDB);
        if(validacionSala == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE PELICULA SET ID_SALA = '%i', TITULO = '%s', SINOPSIS = '%s', HORARIO = '%s' WHERE ID_PELICULA = %i;", idSalaInt, titulo, sinopsis, horario, idPeliculaInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar la película: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Pelicula modificada correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void modificarUsuario(PathDB rutaDB)
{
    validarUsuario(rutaDB);
    if(validacionUsuario == 1)
    {
         sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE USUARIO SET ID_USUARIO = '%i', NOMBRE = '%s', RESPUESTA = '%s', CORREO = '%s', CONTRASENA = '%s WHERE ID_USUARIO = %i;", idUsuarioInt, nombre, respuesta, correo, contrasena, idUsuarioInt);

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

void modificarCine(PathDB rutaDB)
{
    validarCine(rutaDB);
    if(validacionCine == 1)
    {
        sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE CINE SET ID_CINE = '%i', NOMBRE = '%s', DIRECCION = '%s', CIUDAD = '%s' WHERE ID_CINE = %i;", idCineInt, nombreCine, direccionCine, ciudadCine, idCineInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el cine: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Cine modificado correctamente\n");
            }

            sqlite3_close(db);
    }
}

void modificarActor(PathDB rutaDB)
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
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE ACTOR SET ID_ACTOR = '%i', ID_PELICULA = '%i', NOMBRE = '%s' WHERE ID_ACTOR = %i;", idActorInt, idPeliculaInt, nombreActor, idActorInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el actor: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Actor modificado correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void modificarSala(PathDB rutaDB)
{
    validarSala(rutaDB);
    if(validacionSala == 1)
    {
        validarCine(rutaDB);
        if(validacionCine == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE SALA SET ID_SALA = '%i', ID_CINE = '%i', NUMERO = '%i', NCOLUMNAS = '%i', NFILAS = '%i WHERE ID_SALA = %i;", idSalaInt, idCineInt, numeroSalaInt, nColumnasSalaInt, nFilasSalaInt, idSalaInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar la sala: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Sala modificada correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}

void modificarAsiento(PathDB rutaDB)
{
    validarAsiento(rutaDB);
    if(validacionAsiento == 1)
    {
        validarSala(rutaDB);
        if(validacionSala == 1)
        {
            sqlite3 *db;
            char *err_msg = 0;
            int rc = sqlite3_open(rutaDB.ruta, &db);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
                return;
            }

            char sql_modificar[150];
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE ASIENTO SET ID_ASIENTO = '%i', ID_SALA = '%i', FILA = '%i', NUMERO = '%i', FECHA = '%s WHERE ID_ASIENTO = %i;", idAsientoInt, idSalaInt, filaAsientoInt, numeroAsientoInt, fechaAsiento, idAsientoInt);

            rc = sqlite3_exec(db, sql_modificar, 0, 0, &err_msg);

            if (rc != SQLITE_OK) {
                fprintf(stderr, "Error al modificar el asiento: %s\n", err_msg);
                sqlite3_free(err_msg);
            } else {
                printf("Asiento modificado correctamente\n");
            }

            sqlite3_close(db);
        }
    }
}