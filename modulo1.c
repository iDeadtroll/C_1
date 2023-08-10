#include <stdio.h>
#include <stdlib.h>



void write_le_fichier(char *phrase, char *nom_fichier)
{
    FILE *archivox;
    
    archivox = fopen(nom_fichier, "r");
// Si le fichier n'existe pas, il est créé et écrit dedans
    if (archivox == NULL) {
        archivox = fopen(nom_fichier,"w");
        fprintf(archivox,"%s", phrase);
        fclose(archivox);
// Si le fichier existe déjà, il est ouvert en mode 'append' et écrit dedans
    } else {
        archivox = fopen(nom_fichier,"a");
        fprintf(archivox, "%s",phrase);
        fclose(archivox);
    }
}

void introdiure_expression()
{
    char phrase[100];
    char nom_fichier[100];
    printf("Ingrese la palabra o frase: ");
    fgets(phrase,sizeof(phrase),stdin);
    printf("Introduce nombre del archivo: ");
    // fgets(nom_fichier,sizeof(nom_fichier),stdin);

    // // Eliminar el salto de línea del nombre del archivo
    // nom_fichier[strcspn(nom_fichier, "\n")] = '\0';

    scanf(" %[^\n]s", nom_fichier);
    write_le_fichier(phrase,nom_fichier);

}

int main()
{
    introdiure_expression();
    
    return 0;
}
