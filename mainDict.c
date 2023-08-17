// Menú que simula un diccionario donde se puede agregar y mostar expresiones.
#include "modulo1.c"
#include "modulo2.c"
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    char *chemin = "C:\\Users\\joni-\\Documents\\GitHub\\C_1";

    
    setlocale(LC_ALL, "UTF-8"); // Codificación de caracteres

    int option = 0;
    char input[100];

    while (option != 3)
    {
        printf("-------Menu Principal--------\n");
        printf("1. Introducir nueva expresion\n");
        printf("2. Leer expresion\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");

        scanf("%s", input);

        // Verificar si el valor ingresado es un número entero
        int validInput = 1;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (!isdigit(input[i]))
            {
                validInput = 0;
                break;
            }
        }

         if (validInput)
        {
            option = atoi(input); // Convertir el valor a entero
        }
        else
        {
            printf("Opcion inválida. Por favor, seleccione una opción válida\n");
            continue; // Volver al inicio del bucle sin ejecutar el resto del código
        }

        if (option < 1 || option > 3)
        {
            printf("Opcion inválida. Por favor, seleccione una opción válida\n");
            continue; // Volver al inicio del bucle sin ejecutar el resto del código
        }
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