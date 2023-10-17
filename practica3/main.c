#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busquedapp.h"
struct resultados{
    int indice;
    int comparaciones;
};
int main(void){

    int n=10000; //Tamanio del arreglo//5.000,10.000
    int arr[n]; //Declarar el arreglo
    int numbus=50; //Valor a buscar//0,50,99,29
    //variables para exponencial
    int comparaciones=0;

    printf("ESTE TRABAJO SE REALIZO EN COLABORACION DE\nARENAS CESAR\nDOMINGUEZ FRANCISCO\nNAVA DANA\nNAVA JAZMIN\nLUIS MANUEL VAZQUEZ\n");

    srand(time(0)); //Generacion de los numeros aleatorios con semilla en base al tiempo

    for (int i = 0; i < n; i++) { //Inicia el bucle guardando los numeros en un arreglo
        arr[i] = rand() % 100; //Los numeros generados seran hasta el 99
    }

    burbujaS(arr,n); //Ordenamiento con burbuja
    printf("\n");

    printf("VECTOR ORDENADO: ");
    for(int i=0;i<n;i++) //Inicia el bucle buscando el numero declarado en "numbus"
        printf("%d ",arr[i]); //Imprime el arreglo ordenado
    printf("\n\n");

    //BUSQUEDA BINARIA
    struct resultados indice1;
    clock_t inicioBinariaS = clock();
    indice1 = binSearch(arr,0,n-1,numbus);
    clock_t finBinariaS = clock();
    double tiempoBBinaria = ((double)(finBinariaS - inicioBinariaS))/CLOCKS_PER_SEC;

    //BUSQUEDA INDEXADA
    struct resultados indice2;
    clock_t inicioIndexadaS = clock();
    indice2 = indSearch(arr,n,numbus);
    clock_t finIndexadaS = clock();
    int tiempoBIndexada = (finIndexadaS - inicioIndexadaS);

    //BUSQUEDA INTERPOLADA
    struct resultados indice3;
    clock_t inicioInterpolarS = clock();
    indice3 = intSearch(arr,0,n-1,numbus);
    clock_t finInterpolarS = clock();
    double tiempoBInterpolar = (double)(finInterpolarS - inicioInterpolarS);

    //BUSQUEDA LINEAR
    struct resultados indice4;
    clock_t inicioLinearS = clock();
    indice4 = lSearch(arr,n,numbus);
    clock_t finLinearS = clock();
    double tiempoBLinear = (double)(finLinearS - inicioLinearS);

    //BUSQUEDA EXPONENCIAL
    clock_t inicioExponencialS = clock();
    int indice5 = exponential_search(arr, n, numbus, &comparaciones);
    clock_t finExponencialS = clock();
    double tiempoBExponencial = (double) (finExponencialS - inicioExponencialS);


    printf("------------------------------------------------------------------------\n");
    printf("ALGORITMO: BUSQUEDA LINEAL\nANCHO DE VECTOR: %d\nTIEMPO DE EJECUCION: %flsec\nVALOR BUSCADO: %d\nINDICE DEVUELTO: %d\nNUMERO DE COMPARACIONES: %d\n", n, tiempoBLinear, numbus, indice4.indice, indice4.comparaciones);
    printf("------------------------------------------------------------------------\n");
    printf("ALGORITMO: BUSQUEDA BINARIA\nANCHO DE VECTOR: %d\nTIEMPO DE EJECUCION: %flsec\nVALOR BUSCADO: %d\nINDICE DEVUELTO: %d\nNUMERO DE COMPARACIONES: %d\n", n, tiempoBBinaria, numbus, indice1.indice, indice1.comparaciones);
    printf("------------------------------------------------------------------------\n");
    printf("ALGORITMO: BUSQUEDA INDEXADA\nANCHO DE VECTOR: %d\nTIEMPO DE EJECUCION: %dsec\nVALOR BUSCADO: %d\nINDICE DEVUELTO: %d\nNUMERO DE COMPARACIONES: %d\n", n, tiempoBIndexada, numbus, indice2.indice, indice2.comparaciones);
    printf("------------------------------------------------------------------------\n");
    printf("ALGORITMO: BUSQUEDA INTERPOLAR\nANCHO DE VECTOR: %d\nTIEMPO DE EJECUCION: %flsec\nVALOR BUSCADO: %d\nINDICE DEVUELTO: %d\nNUMERO DE COMPARACIONES: %d\n", n, tiempoBInterpolar, numbus, indice3.indice, indice3.comparaciones);
    printf("------------------------------------------------------------------------\n");
    printf("ALGORITMO: BUSQUEDA EXPONENCIAL\nANCHO DE VECTOR: %d\nTIEMPO DE EJECUCION: %flsec\nVALOR BUSCADO: %d\nINDICE DEVUELTO: %d\nNUMERO DE COMPARACIONES: %d\n", n, tiempoBExponencial, numbus, indice5, comparaciones);
    return 0;


}
