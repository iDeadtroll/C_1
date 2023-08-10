#include <stdio.h>
#include <stdlib.h>

void write_le_fichier(char *phrase)
{
//     FILE *archivox;
    
//     archivox = fopen("archivoX.txt", "r");
// // Si le fichier n'existe pas, il est créé et écrit dedans
//     if (archivox == NULL) {
//         archivox = fopen("archivoX.txt","w");
//         fprintf(archivox,"%s", "hola_mundo");
//         fclose(archivox);
// // Si le fichier existe déjà, il est ouvert en mode 'append' et écrit dedans
//     } else {
//         archivox = fopen("archivoX.txt","a");
//         fprintf(archivox, "%s","Hola Mundo");
//         fclose(archivox);
//     }
    printf("%s\n",phrase);
}

int main()
{
    char phrase[100];
    // char chemin[100];
    printf("Ingrese la palabra o frase: ");
    fgets(phrase,sizeof(phrase),stdin);
    // printf("Indica el nombre del archivo: ");
    // fgets(chemin,sizeof(chemin),stdin);
    write_le_fichier(phrase);
    
    return 0;
}
