#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char **vector;
    char aux[20];
    int cantnom;
    printf("Ingrese la cantidad de nombres que se ingresaran:");
    fflush(stdin);
    scanf("%d",&cantnom);
    vector=(char**)malloc(sizeof(char)*cantnom);

    for (int i = 0; i < cantnom; i++)
    {
        printf("Ingrese el nombre en la posicion: %d\n",i+1);
        fflush(stdin);
        gets(aux);
        fflush(stdin);
        vector[i]=(char*)malloc(sizeof(char)*strlen(aux));
        strcpy(vector[i],aux);
    }

 for (int i = 0; i < cantnom; i++)
 {
    printf("El nombre que se ingreso en la posicion numero %d es:",i+1);
    fflush(stdin);
    puts(vector[i]);
 }
 for (int i = 0; i < cantnom; i++)
 {
    free(vector[i]);
 }
 free(vector);
 
    return 0;
}