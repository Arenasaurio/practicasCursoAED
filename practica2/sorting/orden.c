#include "orden.h"
#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

void burbuja(int arreglo[], int longitud) {
    for (int x = 0; x < longitud; x++) {
        for (int indiceActual = 0; indiceActual < longitud - 1; indiceActual++) {
            int indiceSiguienteElemento = indiceActual + 1;
            if (arreglo[indiceActual] > arreglo[indiceSiguienteElemento]) {
                intercambiar(&arreglo[indiceActual], &arreglo[indiceSiguienteElemento]);
            }
        }
    }
}

void seleccion(int arreglo[], int longitud) {
    for (int i = 0; i < longitud - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < longitud; j++) {
            if (arreglo[j] < arreglo[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            intercambiar(&arreglo[i], &arreglo[indiceMenor]);
        }
    }
}

void insercion(int arreglo[], int longitud) {
    for (int i = 1; i < longitud; i++) {
        int valorActual = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > valorActual) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = valorActual;
    }
}

void counting(int arreglo[], int longitud) {
    int max = 0;
    for (int i = 0; i < longitud; i++) {
        if (arreglo[i] > max) {
            max = arreglo[i];
        }
    }

    int conteo[max + 1];
    for (int i = 0; i < max + 1; i++) {
        conteo[i] = 0;
    }

    for (int i = 0; i < longitud; i++) {
        conteo[arreglo[i]]++;
    }

    int indiceArreglo = 0;
    for (int i = 0; i < max + 1; i++) {
        while (conteo[i] > 0) {
            arreglo[indiceArreglo] = i;
            indiceArreglo++;
            conteo[i]--;
        }
    }
}
