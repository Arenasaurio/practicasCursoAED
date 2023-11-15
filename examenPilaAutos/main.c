#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 100

int pila[MAXIMO];
int ind=1;

int pop(){
    if(ind!=0){
        return pila[--ind];
    }
    else{
        return -1;
    }

}
void apilar(int valor){
    if(ind==MAXIMO)
        printf("DEMASIADO GRANDE ONII CHAN\n ERRRRROR");
    else{
        pila[ind]=valor;
        ind++;
    }
}

int main()

{
    pila[0]=0;
    int valor, nAutos, busq, contador=0, aux;
    printf("PROPORCIONA EL NUMERO DE AUTOS EN EL ESTACIONAMIENTO: ");
    scanf("%d", &nAutos);
     printf("DAME LAS PLACAS:\n");
    for (int i=1; i<=nAutos; i++){
        scanf("%d", &valor);
        apilar(valor);
    }
    printf("DAME LAS PLACAS A BUSCAR: ");scanf("%d", &busq);
    while(aux!=0){
        aux=pop();
        contador++;
        if(aux==busq){
            printf("%d ", contador)-1;
            contador=0;
        }
    }
    if (contador==0){
        printf("No existe el auto");
    }
    else
        printf("%d", contador-1);

return 0;
}

