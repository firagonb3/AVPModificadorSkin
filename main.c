/*
 * Copyright (C) 2024 Marc Lecha Blesa
 *
 * Este programa es software libre; puedes redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General de GNU según se publicó
 * por la Free Software Foundation; ya sea la versión 3 de la Licencia, o
 * (a tu elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de
 * COMERCIABILIDAD o ADECUACIÓN A UN PROPÓSITO PARTICULAR.
 * Consulta la Licencia Pública General de GNU para más detalles.
 *
 * Debes haber recibido una copia de la Licencia Pública General de GNU
 * junto con este programa; si no, consulta <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define TAMANO_DIRECTORIO 512

int obtener_directorio_AVP(char *directorio_base)
{
    // Obtener el nombre de usuario desde la variable de entorno %USERNAME%
    const char *username = getenv("USERNAME");

    if (username == NULL)
    {
        printf("No se pudo obtener la variable de entorno USERNAME\n");
        return 1;
    }

    // Construir la ruta usando el nombre de usuario
    snprintf(directorio_base, TAMANO_DIRECTORIO, "C:\\Users\\%s\\AppData\\Local\\AliensVsPredator", username);
    // printf("Ruta construida: %s\n", directorio_base);
    return 0;
}

int es_directorio(const char *ruta)
{
    struct stat st;
    // Verificar si es un directorio usando stat() y S_ISDIR()
    if (stat(ruta, &st) == 0 && S_ISDIR(st.st_mode))
        return 1;
    return 0;
}

int generar_ruta_prf(char *ruta_archivo_completa)
{
    DIR *dir;
    struct dirent *ent;

    // Abrir el directorio base
    if ((dir = opendir(ruta_archivo_completa)) == NULL)
    {
        printf("No se pudo abrir el directorio: %s\n", ruta_archivo_completa);
        return 1;
    }

    // Leer cada carpeta/archivo en el directorio base
    while ((ent = readdir(dir)) != NULL)
    {
        // Ignorar "." y ".."
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
        {
            // Construir la ruta completa de la carpeta encontrada
            char ruta_directorio[TAMANO_DIRECTORIO];
            snprintf(ruta_directorio, sizeof(ruta_directorio), "%s\\%s", ruta_archivo_completa, ent->d_name);

            // Verificar si es un directorio usando stat()
            if (es_directorio(ruta_directorio))
            {
                // Construir la ruta completa del archivo .prf
                snprintf(ruta_archivo_completa, TAMANO_DIRECTORIO, "%s\\%s\\%s.prf", ruta_archivo_completa, ent->d_name, ent->d_name);
                printf("Ruta construida: %s\n", ruta_archivo_completa);
                closedir(dir);
                return 0;
            }
        }
    }

    closedir(dir);
    printf("No se encontró ninguna carpeta en %s\n", ruta_archivo_completa);
    return 1;
}

int modificar_archivo_prf(const char *ruta_archivo, long posicion, unsigned char nuevo_valor)
{
    // Abrir el archivo en modo lectura/escritura binaria
    FILE *archivo = fopen(ruta_archivo, "rb+");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo: %s\n", ruta_archivo);
        return 1;
    }

    // Ir a la direccion hex
    fseek(archivo, posicion, SEEK_SET);

    // Escribir el nuevo valor hex
    fwrite(&nuevo_valor, 1, 1, archivo);

    // Cerrar el archivo
    fclose(archivo);

    printf("Se modifico la posicion %lx con el valor %x en el archivo %s.\n", posicion, nuevo_valor, ruta_archivo);
    return 0;
}

int main()
{
    char ruta_completa_prf[TAMANO_DIRECTORIO];

    // Llamar a la función para obtener el directorio AVP
    if (obtener_directorio_AVP(ruta_completa_prf) != 0)
    {
        printf("Error al obtener el directorio AVP\n");
        return 1;
    }

    // Generar la ruta del archivo .prf
    if (generar_ruta_prf(ruta_completa_prf) != 0)
    {
        printf("Error al generar la ruta del archivo .prf\n");
        return 1;
    }

    // Obtener las direcciones hex
    long direccion_hex      = 0x00000A20;
    long offset_predator    = 0x05;
    long offset_alien       = 0x09;
    long offset_Marin       = 0x0D;

    // Obtener la posicion real hex
    long posicion_predator  = direccion_hex + offset_predator;
    long posicion_alien     = direccion_hex + offset_alien;
    long posicion_Mari      = direccion_hex + offset_Marin;

    // Skin pre order
    unsigned char skin_predator_alien   = 0x07;
    unsigned char skin_alien_Number6    = 0x02;
    unsigned char skin_Marine_Kaneko    = 0x04;

    // Modificar el archivo .prf
    modificar_archivo_prf(ruta_completa_prf, posicion_predator, skin_predator_alien);
    modificar_archivo_prf(ruta_completa_prf, posicion_alien, skin_alien_Number6);
    modificar_archivo_prf(ruta_completa_prf, posicion_Mari, skin_Marine_Kaneko);

    //getchar();

    return 0;
}
