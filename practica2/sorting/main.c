#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "orden.h"

// Función para generar un arreglo de números aleatorios de tamaño n
void generarArregloAleatorio(int arr[], int n) {
    srand(time(NULL)); // Inicializar la semilla para números aleatorios

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Genera números aleatorios entre 0 y 999 (puedes ajustar el rango)
    }
}
// Función para medir el tiempo de ejecución de una función de ordenamiento
void medirTiempo(void (*ordenamiento)(int[], int), int arr[], int longitud, const char* nombre) {
    clock_t inicio, fin;
    double tiempo;

    inicio = clock();
    ordenamiento(arr, longitud);
    fin = clock();

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion de %s: %lf segundos\n", nombre, tiempo);
}

int main() {
    int n = 10; // Tamaño del arreglo aleatorio

    int arreglo[n];

    // Generar el arreglo aleatorio
    generarArregloAleatorio(arreglo, n);
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    // Medir el tiempo de ejecución del algoritmo Gnome Sort
    medirTiempo(bucketSort, arreglo, longitud, "bucketsort");

    printf("Arreglo ordenado: ");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", arreglo[i]);
    }

    return 0;
}
