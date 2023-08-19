// Módulo para simular el funcionamiento de una agenda
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_CONTACTS 5

struct Contact
{
    char nombre[50];
    char numero[20];
};

struct Contact agenda[MAX_CONTACTS];
int numContacts = 0;

void ajouter_des_contacts()
{
   

    char autre;
    do
    {
         if (numContacts >= MAX_CONTACTS)
    {
        printf("La agenda está llena. No se pueden agregar más contactos.\n");
        return;
    }
        printf("Nom du contact: ");
        char nombre[50];
        scanf("%s", nombre);

        int i;
        for (i = 0; i < numContacts; i++)
        {
            if (strcmp(nombre, agenda[i].nombre) == 0)
            {
                printf("Le nom %s est déjà enregistré, et son numéro est %s\n", nombre, agenda[i].numero);
                break;
            }
        }

        if (i == numContacts)
        {
            strcpy(agenda[numContacts].nombre, nombre);
            printf("Entrez un numero: ");
            scanf("%s", agenda[numContacts].numero);
            numContacts++;
        }
        
        printf("Voulez-vous ajouter un autre contact?\n");
        printf("oui: Appuie 'o'\n");
        printf("non: Appuie outre touche pour sorti\n");
        printf("oui/non: ");
        autre = getch();
        putchar(autre);
        printf("\n");
    } while (autre == 'o' || autre == 'O');
}

void afficher_les_contacts()
{
    for (int i = 0; i < numContacts; i++)
    {
        printf("%d. %s: %s\n", i + 1, agenda[i].nombre, agenda[i].numero);
    }
    printf("\n");
}
