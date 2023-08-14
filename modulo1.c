#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>




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

void read_le_fichier()
{
    FILE *fichier;
    char nom_fichier[100];
    printf("Indica el nombre del archivo: ");
    scanf(" %[^\n]s", nom_fichier);
    fichier = fopen(nom_fichier, "r");
    // Si el archivo existe se leen las lineas del archivo
    if (fichier == NULL)
    {
        printf("El archivo no se pudo abrir");
    }else{
        char linea[100];
        while (fgets(linea,sizeof(linea),fichier) != NULL )
        {
            printf("%s",linea);
        }
    }
    fclose(fichier);
    
}

void introdiure_expression()
{
    char phrase[100];
    char nom_fichier[100];
    printf("Ingrese la palabra o frase: ");
    // Funcion para obtener entrada 1
    scanf("%s",phrase);

    printf("Introduce nombre del archivo: ");
    // Funcion para obtener entrada 2: conveniente para nombre de archivo
    scanf(" %[^\n]s", nom_fichier);
    write_le_fichier(phrase,nom_fichier);

}

