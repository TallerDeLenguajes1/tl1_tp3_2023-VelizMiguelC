#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={“Galletas”,”Snack”,”Cigarrillos”,”Caramelos”,”Bebidas”};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;

void cargarclientes(Cliente *cliente,int cantidad);
void mostrarclientes(Cliente *cliente,int cantidad);
float calcularcosto(Producto Producto);

int main (){
    int cantcli=10;
    Cliente *clientes;
    
    while (cantcli > 5)
    {
        printf("Ingrese la cantidad de clientes:");
        scanf("%d",cantcli);
        if (cantcli > 5)
        {
            printf("La cantidad de clientes es como maximo 5:");
        }
        
    }
    clientes = malloc(sizeof(Cliente) * cantcli);
    cargarclientes(clientes,cantcli);
    mostrarclientes(cliente,cantcli);
    
    return 0;
}


void cargarclientes(Cliente *cliente,int cantidad){
    char aux[20];
    srand(time(NULL));
    int id = 1;
    int precio = 0;
    for (int i = 0; i < cantidad; i++)
    {
        printf("ingrese el nombre del cliente numero %d:  ", i + 1);
        gets(aux);
        fflush(stdin);
        clientes[i].nombreCliente = (char *)malloc(sizeof(char) * strlen(aux));
        strcpy(clientes[i].nombreCliente, aux);
        clientes[i].clienteID = i + 1;
        clientes[i].cantPedidos = 1 + rand() % (6 - 1);
        clientes[i].productos = malloc(sizeof(Producto) * clientes[i].cantPedidos);
        for (int j = 0; j < clientes[i].cantPedidos; j++)
        {
            clientes[i].productos[j].productoId = id;
            clientes[i].productos[j].cantidad = 1 + rand() % 10;
            clientes[i].productos[j].TipoProducto = malloc(sizeof(char) * 12);
            strcpy(clientes[i].productos[j].TipoProducto, tipoProductos[rand() % 5]);
            precio = 10 + rand() % 100;
            clientes[i].productos[j].PrecioUnitario = ((float)(10 + rand() % 10100)) / 100;
            id++;
        }
    }
}


void mostrarclientes(Cliente *cliente,int cantidad){
    float total = 0;
    float costoProducto = 0;

    for (int i = 0; i < cantidad; i++)
    {
        printf(" \n el id del cliente es %d ", clientes[i].clienteID);
        printf(" \n el nombre del cliente es : ");
        puts(clientes[i].nombreCliente);
        printf("la cantidad de productos pedidos es : ");
        printf("%d \n", clientes[i].cantPedidos);
        for (int j = 0; j < clientes[i].cantPedidos; j++)
        {
            printf("************** *********** ***********");
            printf(" \n producto numero %d \n", j + 1);
            printf("el producto es : ");
            puts(clientes[i].productos[j].TipoProducto);
            printf(" El id del producto es %d \n", clientes[i].productos[j].productoId);
            printf(" La cantidad de unidades es %d \n", clientes[i].productos[j].cantidad);
            printf(" El precio por unidad del producto es %.2f \n", clientes[i].productos[j].PrecioUnitario);
            costoProducto = calcularCosto(clientes[i].productos[j]);
            printf("El total por estos productos es de $%.2f \n, ", costoProducto);
            total += costoProducto;
        }
    }
    printf("El Total de todos los productos de todos los clientes es de %.2f", total);
}
float calcularCosto(Producto Producto){
    return Producto.cantidad * Producto.PrecioUnitario;
}