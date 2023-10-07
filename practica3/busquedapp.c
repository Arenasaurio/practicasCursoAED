#include "busquedapp.h"

#include <time.h>
#include <stdlib.h>
//definicion de las funciones de los algoritmos de busqueda
struct resultados{
    int indice;
    int comparaciones;
};
struct resultados lSearch(int A[],int n,int vB)
{
    struct resultados lineal;
    lineal.comparaciones=0;
    for(int i=0;i<n;i++){
        lineal.comparaciones++;
        if(A[i]==vB){
        lineal.comparaciones++;
        lineal.indice=i;
        return lineal;}
    }
    lineal.indice=-1;
    return lineal;
}

void burbujaS(int A[],int n){
    int swap;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
            if(A[j]>A[j+1])
            {
                swap=A[j];
                A[j]=A[j+1];
                A[j+1]=swap;
            }
}

struct resultados binSearch(int A[],int inicio,int fin,int vB){
    struct resultados binaria;
    binaria.comparaciones=0;
    while(inicio<=fin)
    {
        int mid=inicio+(fin-inicio)/2;//int mid=(inicio+fin)/2;
        binaria.comparaciones++;
        if(A[mid]==vB){binaria.indice=mid;//si el valor es mid
            return binaria;}
        else if(vB>A[mid]) //buscar del lado derecho
            inicio=mid+1;
        else
            fin=mid-1;
    }
    binaria.indice=-1;
    return binaria;
}


struct resultados indSearch(int A[],int n, int vB)
{
    struct resultados indexada;
    indexada.comparaciones=0;
    int indices[n],elementos[n],i,set=0;
    int inicio, fin,ind=0;   // inicio y fin de rango de busqueda, ind es indices deindices y elementos

    //crear los limites
    for(i=0;i<n;i+=3)
    {
        indices[ind]=i;
        elementos[ind]=A[i];
        ind++;
    }
    //verificar si el valor buscado
    //esta dentro del arreglo
    if(vB<A[0] || vB>A[n-1])
        {indexada.comparaciones++;
        indexada.indice=-1;
        return indexada;}
    else
    {
        for(i=1;i<=ind;i++)
            if(vB<=elementos[i])
            {
                //generamos rango de busqueda
                inicio=indices[i-1]; //indice anterior
                fin=indices[i]; //inide actual
                set=1;
                break;
            }
    }
    if(set==0)
    {
        inicio=indices[i];
        fin=n-1;
    }


    for(i=inicio;i<fin;i++)
    {
        indexada.comparaciones++;
        if(vB==A[i]){
            indexada.indice=i;
            return indexada;
        }
    }

    indexada.indice=-1;
    return indexada;
}

struct resultados intSearch(int A[],int inicio,int fin,int vB)
{
    struct resultados interpolar;
    interpolar.comparaciones=0;
    int pos; //posici�n aproximada del valor
    while(inicio<=fin && vB>=A[inicio] && vB<=A[fin])
    {
        pos=inicio+((vB-A[inicio])*(fin-inicio)/(A[fin]-A[inicio]));
        interpolar.comparaciones++;
        if(vB==A[pos]){
            interpolar.indice=pos;
            return interpolar;
        }
        else if (vB<A[pos])
            fin=pos-1;
        else
            inicio=pos+1;

    }
    interpolar.indice=-1;
    return interpolar;
}

//Busqueda agregada.
int exponential_search(int arr[], int n, int x, int* comparisons) {
    if (arr[0] == x) {
        *comparisons = 1;
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= x) {
        i *= 2;
        (*comparisons)++;
    }

    return binariasimple(arr, i / 2, (i < n) ? i : n, x, comparisons);
}

int binariasimple(int arr[], int low, int high, int x, int* comparisons) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            (*comparisons)++;
            return mid;
        }

        if (arr[mid] > x) {
            (*comparisons)++;
            return binariasimple(arr, low, mid - 1, x, comparisons);
        }

        (*comparisons)++;
        return binariasimple(arr, mid + 1, high, x, comparisons);
    }

    return -1;
}

















