#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define F 5
#define C 12
void cargarmatriz(int matriz[5][12]);
float calcularprom(int matriz[5][12],int valor);
void minvalor(int matriz[5][12]);
void maxvalor(int matriz[5][12]);
int main (){
    srand (time(NULL)); 
    /*2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
        generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
        es un mes. Ud. debe realizar las siguientes tareas:
         a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
         b. Muestre por pantalla los valores cargados
         c. Saque el promedio de ganancia por año y muestrelos por pantalla
         d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.*/
        
    int matriz[F][C],valor=1;
    float prom[5];
    cargarmatriz(matriz);
      for (int i = 0; i < F; i++) {
        prom[i] = calcularprom(matriz, i);
        printf("El promedio de ganancias del anio %d es: %f\n", i+1, prom[i]);
    }
    minvalor(matriz);
    maxvalor(matriz);
    return 0;
    
    
}
void cargarmatriz(int matriz[F][C]) {
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            matriz[i][j] = 10000 + rand() % 40001;
            printf("Anio %d y mes %d se produjo: %d\n", i+1, j+1, matriz[i][j]);
        }
    }
}

float calcularprom(int matriz[F][C], int i) {
    float suma = 0;
    for (int j = 0; j < C; j++) {
        suma += matriz[i][j];
    }
    return suma / C;
}
//,valorMax, valorMin,anio[2], mes[2]
void minvalor(int matriz[5][12]){
    int valorMin=51000,anio, mes;
        for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (valorMin>matriz[i][j])
            {
                valorMin=matriz[i][j];
                anio=i+1;
                mes=j+1;
            }
            
        }
    }
    printf("El menor valor fue en el anio %d en el mes %d y es %d\n",anio,mes,valorMin);
    
}
void maxvalor(int matriz[5][12]){
    int valorMax, anio, mes;
            for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (valorMax<matriz[i][j])
            {
                valorMax=matriz[i][j];
                anio=i+1;
                mes=j+1;
            }
            
        }
    }
    printf("El mayor valor fue en el anio %d en el mes %d y es %d",anio,mes,valorMax);
}