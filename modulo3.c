//Módulo para simular el funcionamiento de una agenda
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 10

struct Contact {
    char nombre[50];
    char numero[20];
};

struct Contact agenda[MAX_CONTACTS];
int numContacts = 0;

void ajouter_des_contacts() {
    if (numContacts >= MAX_CONTACTS) {
        printf("La agenda está llena. No se pueden agregar más contactos.\n");
        return;
    }

    char autre;
    do {
        printf("Nom du contact: ");
        char nombre[50];
        scanf("%s", nombre);

        int i;
        for (i = 0; i < numContacts; i++) {
            if (strcmp(nombre, agenda[i].nombre) == 0) {
                printf("Le nom %s est déjà enregistré, et son numéro est %s\n", nombre, agenda[i].numero);
                break;
            }
        }

        if (i == numContacts) {
            strcpy(agenda[numContacts].nombre, nombre);
            printf("Entrez un numero: ");
            scanf("%s", agenda[numContacts].numero);
            numContacts++;
        }

        printf("Voulez-vous ajouter un autre contact? (oui/non)\n");
        scanf(" %c", &autre);
    } while (autre == 'o' || autre == 'O');
}

void afficher_les_contacts() {
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", agenda[i].nombre, agenda[i].numero);
    }
    printf("\n");
}

int main() {
    ajouter_des_contacts();
    afficher_les_contacts();
    return 0;
}