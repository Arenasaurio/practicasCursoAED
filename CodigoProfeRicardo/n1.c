#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//definicion de las funciones de los algoritmos de búsqueda
int lSearch(int [],int,int); //lSearch(VectorD,tamaño,valor Buscado);
void burbujaS(int [],int); //algoritmo de ordenamiento
int binSearch(int [],int,int,int); //binSearch(vectorO,inicio,fin,vB)
int indSearch(int[],int,int); //indSearch(VectorO,tamaño,vB);
int intSearch(int [],int,int,int); //intSearch(vectorO,inicio,fin,vB);

int main(){
    const int n=10;
    int A[n];
    int vB=3; //Valors Buscado

    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        A[i]=rand()%11;
        printf("%d ",A[i]);
        }
    //int indice= lSearch(A,n,vB);
    burbujaS(A,n); //ordenamos el vector
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    //int indice= indSearch(A,n,vB);
    int indice= lSearch(A,n,vB); //considere que n es tamaño y n-1 es el INDICE FINAL del vector SON VALORES DIFERENES

    if(indice!=-1)
        printf("\nEl valor %d esta en: %d",vB,indice);
    else
        printf("\nEl valor no se encuentra en la lista");
    return 0;
}

int lSearch(int A[],int n,int vB)
{
    for(int i=0;i<n;i++)
        if(A[i]==vB)
            return i;
    return -1;
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
    int pos; //posición aproximada del valor
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





























