#include "modulo3.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int main()
{   
    int option = 0;
    char input[100];

    while (option != 3)
    {
        printf("-------Menu Principal--------\n");
        printf("1. Añadir contactos\n");
        printf("2. Mostrar contactos\n");
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

            if (option == 1)
            {
                ajouter_des_contacts();
            }
            else if (option == 2)
            {
                afficher_les_contacts();
            }
            else if (option == 3)
            {
                printf("Adios....");
            }
            else
            {
                printf("Opcion inválida. Por favor, seleccione una opción válida\n");
            }
        }
        else
        {
            printf("Opcion inválida. Por favor, seleccione una opción válida\n");
        }

    }
    return 0;

}