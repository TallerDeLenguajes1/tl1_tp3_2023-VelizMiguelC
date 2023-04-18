#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char **vector;
    char aux[20];

    vector=(char*)malloc(sizeof(char)*5);

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre en la posicion: %d\n",i);
        gets(aux);
        fflush(stdin);
        vector[i]=(char*)malloc(sizeof(char)*strlen(aux));
        strcpy(vector[i],aux);
    }

 for (int i = 0; i < 5; i++)
 {
    printf("El nombre que se ingreso en la posicion numero %d es:",i)
    puts(vector);
 }
 for (int i = 0; i < 5; i++)
 {
    free(vector[i]);
 }
 free(vector);
 
    return 0;
}