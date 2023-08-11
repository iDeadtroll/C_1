#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int tieneExtension(const char *nombreArchivo)
{
    const char *punto = strrchr(nombreArchivo, '.'); // Busca el último punto en el nombre del archivo

    // Si no hay punto o el punto está al principio del nombre o es el último carácter, no tiene extensión
    if (punto == NULL || punto == nombreArchivo || punto == nombreArchivo + strlen(nombreArchivo) - 1)
    {
        return 0; // No tiene extensión
    }

    return 1; // Tiene extensión
}

void mostrarArchivosSinExtension(const char *rutaDirectorio)
{
    DIR *directorio;
    // DIR *directorio : es un puntero a una estructura DIR que representa un directorio. Se utiliza para abrir y leer el contenido del directorio especificado.
    struct dirent *entrada;
    // struct dirent *entrada : es un puntero a una estructura dirent que contiene información sobre una entrada en el directorio. Se utiliza para leer cada entrada del directorio.
    struct stat infoArchivo;
    // struct stat infoArchivo : es una estructura stat que contiene información sobre un archivo. Se utiliza para obtener información sobre el archivo, como el tipo y los permisos.

    directorio = opendir(rutaDirectorio); // Abre el directorio

    if (directorio == NULL)
    {
        printf("No se pudo abrir el directorio.\n");
        return;
    }

    while ((entrada = readdir(directorio)) != NULL)
    { // Lee cada entrada del directorio
        char rutaCompleta[100];
        //      Para cada entrada, se construye la ruta completa del archivo utilizando  snprintf
        snprintf(rutaCompleta, sizeof(rutaCompleta), "%s/%s", rutaDirectorio, entrada->d_name);
        //      Se obtiene información sobre el archivo utilizando  stat
        stat(rutaCompleta, &infoArchivo);

        if (S_ISREG(infoArchivo.st_mode))
        { // Verifica si es un archivo regular
            // Busca la extensión del archivo
            const char *extension = strrchr(entrada->d_name, '.');
            // Busca el último punto en el nombre del archivo y se utiliza para buscar el último punto en el nombre del archivo y obtener la extensión.

            // Verifica si no tiene extensión ó si la extensión es .txt
            if (!tieneExtension(entrada->d_name) || (extension != NULL && strcmp(extension, ".txt") == 0))
            // -  strcmp(const char *str1, const char *str2) : Esta función compara las cadenas  str1  y  str2  y devuelve un valor entero. Si el valor devuelto es menor que 0, significa que  str1  es menor que  str2 . Si el valor es igual a 0, significa que las cadenas son iguales. Y si el valor es mayor que 0, significa que  str1  es mayor que  str2 . En el código proporcionado, se utiliza para comparar la extensión del archivo con ".txt" y determinar si coinciden.

            {
                printf("%s\n", entrada->d_name); // Muestra el nombre del archivo sin extensión
            }
        }
    }

    closedir(directorio); // Cierra el directorio
}