#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "orden.h"

int main() {
    int n;
    printf("Ingresa la cantidad de números aleatorios: ");
    scanf("%d", &n);
//CREACION DEL VECTOR DE TAMANO N CON NUMEROS ALEATORIOS DEL 1 AL 100
    int lista[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % 100;
    }
//ALGORITMOS Y SUS RELOJES---------------------------------------------------------------------------------------
    //burbuja
    /*clock_t inicioBurbuja = clock();
    burbuja(lista, n);
    clock_t finBurbuja = clock();
    double tiempoBurbuja = (double)(finBurbuja - inicioBurbuja) / CLOCKS_PER_SEC;*/

    //seleccion
    /*clock_t inicioSeleccion = clock();
    seleccion(lista, n);
    clock_t finSeleccion = clock();
    double tiempoSeleccion = (double)(finSeleccion - inicioSeleccion) / CLOCKS_PER_SEC;*/

    //insercion
    /*clock_t inicioInsercion = clock();
    insercion(lista, n);
    clock_t finInsercion = clock();
    double tiempoInsercion = (double)(finInsercion - inicioInsercion) / CLOCKS_PER_SEC;*/

    //counting
    /*clock_t inicioCounting = clock();
    counting(lista, n);
    clock_t finCounting = clock();
    double tiempoCounting = (double)(finCounting - inicioCounting) / CLOCKS_PER_SEC;*/

    //bucket
    /*clock_t inicioBucket = clock();
    bucketSort(lista, n);
    clock_t finBucket = clock();
    double tiempoBucket = (double)(finBucket - inicioBucket) / CLOCKS_PER_SEC;*/

    //timsort
    /*clock_t inicioTimsort = clock();
    timsort(lista, n);
    clock_t finTimsort = clock();
    double tiempoTimsort = (double)(finTimsort - inicioTimsort) / CLOCKS_PER_SEC;*/

    // quicksort
    /*clock_t inicioQuicksort = clock();
    quicksort(lista, 0, n - 1);
    clock_t finQuicksort = clock();
    double tiempoQuicksort = (double)(finQuicksort - inicioQuicksort) / CLOCKS_PER_SEC;*/

    //gnome
    clock_t inicioGnome = clock();
    gnomeSort(lista, n);
    clock_t finGnome = clock();
    double tiempoGnome = (double)(finGnome - inicioGnome) / CLOCKS_PER_SEC;


    //IMPRESION DE LOS TIEMPOS DE EJECUCION------------------------------------------------------------------------------------------
    //printf("\n\nTiempo de ejecución del algoritmo de burbuja: %.6f segundos\n", tiempoBurbuja);
    //printf("\n\nTiempo de ejecución del algoritmo por seleccion: %.6f segundos\n", tiempoSeleccion);
    //printf("\n\nTiempo de ejecución del algoritmo por insercion: %.6f segundos\n", tiempoInsercion);
    //printf("\n\nTiempo de ejecución del algoritmo por conteo: %.6f segundos\n", tiempoCounting);
    //printf("\n\nTiempo de ejecución del algoritmo de bucket: %.6f segundos\n", tiempoBucket);
    //printf("\n\nTiempo de ejecución del algoritmo de timsort: %.6f segundos\n", tiempoTimsort);
    //printf("\n\nTiempo de ejecución del algoritmo quicksort: %.6f segundos\n", tiempoQuicksort);
    printf("\n\nTiempo de ejecución del algoritmo gnome: %.6f segundos\n", tiempoGnome);

    return 0;
}


