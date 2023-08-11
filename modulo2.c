#include <stdio.h>
#include <dirent.h>
#include <string.h>

int tieneExtension(const char *nombreArchivo) {
    const char *punto = strrchr(nombreArchivo, '.'); // Busca el último punto en el nombre del archivo

    // Si no hay punto o el punto está al principio del nombre o es el último carácter, no tiene extensión
    if (punto == NULL || punto == nombreArchivo || punto == nombreArchivo + strlen(nombreArchivo) - 1) {
        return 0; // No tiene extensión
    }

    return 1; // Tiene extensión
}

void mostrarArchivosSinExtension(const char *rutaDirectorio) {
    DIR *directorio;
    struct dirent *entrada;

    directorio = opendir(rutaDirectorio); // Abre el directorio

    if (directorio == NULL) {
        printf("No se pudo abrir el directorio.\n");
        return;
    }

    while ((entrada = readdir(directorio)) != NULL) { // Lee cada entrada del directorio
        if (entrada->d_type == DT_REG) { // Verifica si es un archivo regular
            // Busca la extensión del archivo
            const char *extension = strrchr(entrada->d_name, '.');
            // Verifica si no tiene extensión ó si la extensión es .txt
            if (!tieneExtension(entrada->d_name) || extension != NULL && strcmp(extension, ".txt") == 0) { 
                printf("%s\n", entrada->d_name); // Muestra el nombre del archivo sin extensión
            }
        }
    }

    closedir(directorio); // Cierra el directorio
}