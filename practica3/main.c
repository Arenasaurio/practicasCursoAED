#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busquedapp.h"
struct resultados{
    int indice;
    int comparaciones;
};
int main(void){

    int n=10; //Tamanio del arreglo
    int arr[n]; //Declarar el arreglo
    int numbus=0; //Valor a buscar

    printf("ESTE TRABAJO SE REALIZO EN COLABORACION DE\nARENAS CESAR\nDOMINGUEZ FRANCISCO\nNAVA DANA\nNAVA JAZMIN\nLUIS MANUEL VAZQUEZ\n");

    srand(time(0)); //Generacion de los numeros aleatorios con semilla en base al tiempo

    for (int i = 0; i < n; i++) { //Inicia el bucle guardando los numeros en un arreglo
        arr[i] = rand() % 99; //Los numeros generados seran hasta el 99
    }

    burbujaS(arr,n); //Ordenamiento con burbuja
    printf("\n");

    printf("Arreglo ordenado: ");
    for(int i=0;i<n;i++) //Inicia el bucle buscando el numero declarado en "numbus"
        printf("%d ",arr[i]); //Imprime el arreglo ordenado


    //BUSQUEDA BINARIA
    clock_t inicioBinariaS = clock();
    int indice1 = binSearch(arr,0,n-1,numbus);
    clock_t finBinariaS = clock();
    double tiempoBBinaria = (double)(finBinariaS - inicioBinariaS) / CLOCKS_PER_SEC;
    if(indice1!=-1)
        printf("\nEl valor %d, con  Busqueda Interpolada esta en: %d",numbus, indice1);
    else
        printf("\nEl valor %d, con Busqueda Interpolada no se encuentra en la lista", numbus);

    //BUSQUEDA INDEXADA
    clock_t inicioIndexadaS = clock();
    int indice2 = indSearch(arr,n,numbus);
    clock_t finIndexadaS = clock();
    double tiempoBIndexada = (double)(finIndexadaS - inicioIndexadaS) / CLOCKS_PER_SEC;
    if(indice2!=-1)
        printf("\nEl valor %d, con Busqueda Indexada esta en: %d",numbus, indice2);
    else
        printf("\nEl valor %d, con Busqueda Indexada no esta en la lista", numbus);

    //BUSQUEDA INTERPOLADA
    clock_t inicioInterpolarS = clock();
    int indice3 = intSearch(arr,0,n-1,numbus);
    clock_t finInterpolarS = clock();
    double tiempoBInterpolar = (double)(finInterpolarS - inicioInterpolarS) / CLOCKS_PER_SEC;
    if(indice3!=-1)
        printf("\nEl valor %d, con Busqueda Interpolada esta en: %d",numbus, indice3);
    else
        printf("\nEl valor %d, con Busqueda Interpolada no se encuentra en la lista",numbus);

    //BUSQUEDA LINEAR
    struct resultados indice4;
    clock_t inicioLinearS = clock();
    indice4 = lSearch(arr,n,numbus);
    clock_t finLinearS = clock();
    double tiempoBLinear = (double)(finLinearS - inicioLinearS) / CLOCKS_PER_SEC;
    printf("Comparaciones: %d\nIndice: %d", indice4.comparaciones, indice4.indice);
    return 0;


}
