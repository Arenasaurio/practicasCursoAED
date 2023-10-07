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

int binSearch(int A[],int inicio,int fin,int vB){
    while(inicio<=fin)
    {
               int mid=inicio+(fin-inicio)/2;//int mid=(inicio+fin)/2;
        if(A[mid]==vB) //si el valor es mid
            return mid;
        else if(vB>A[mid]) //buscar del lado derecho
            inicio=mid+1;
        else
            fin=mid-1;
    }
    return -1;
}


int indSearch(int A[],int n, int vB)
{
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
        return -1;
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
        if(vB==A[i])
            return i;
    }

    return -1;
}

int intSearch(int A[],int inicio,int fin,int vB)
{
    int pos; //posici�n aproximada del valor
    while(inicio<=fin && vB>=A[inicio] && vB<=A[fin])
    {
        pos=inicio+((vB-A[inicio])*(fin-inicio)/(A[fin]-A[inicio]));
        if(vB==A[pos])
            return pos;
        else if (vB<A[pos])
            fin=pos-1;
        else
            inicio=pos+1;

    }
    return -1;
}


















