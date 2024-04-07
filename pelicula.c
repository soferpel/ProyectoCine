#include "configuracion.h"
#include "pelicula.h"
#include "baseDeDatos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al realizar la consulta SELECT: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
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
        if (pelicula.idPeliculaInt == idPelicula)
        {
            validacionPelicula = 1;
            break;
        }
    }

    return validacionPelicula;
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
        snprintf(sql_anadir, sizeof(sql_anadir), "INSERT INTO PELICULA (ID_SALA, TITULO, SINOPSIS, HORARIO) VALUES ('%i', '%s', '%s', '%s');", sala.idSalaInt, pelicula.titulo, pelicula.sinopsis, pelicula.horario);

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
            snprintf(sql_modificar, sizeof(sql_modificar), "UPDATE PELICULA SET ID_SALA = '%i', TITULO = '%s', SINOPSIS = '%s', HORARIO = '%s' WHERE ID_PELICULA = %i;", sala.idSalaInt, pelicula.titulo, pelicula.sinopsis, pelicula.horario, pelicula.idPeliculaInt);

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