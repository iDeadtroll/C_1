#include "modulo1.c"
#include <stdio.h>
#include <locale.h>

int main()
{
    char *chemin = "C:\\Users\\joni-\\Documents\\GitHub\\C_1";

    
    setlocale(LC_ALL, "UTF-8"); // Codificación de caracteres

    int option = 0;
    while (option != 3)
    {
        printf("-------Menu Principal--------\n");
        printf("1. Introducir nueva expresion\n");
        printf("2. Leer expresion\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            introdiure_expression();
            break;

        case 2:
            mostrarArchivos(chemin);
            read_le_fichier();
            break;

        case 3:
            printf("Saliendo......");
            break;

        default:
            printf("Opcion inválida. Por favor, seleccione una opción válida\n");
            break;
        }
    }

    return 0;
}