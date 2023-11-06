#include <stdio.h>
#include <stdlib.h>

struct Nodo{//almacena tanto el dato como el puntero siguiente
    int dato;
    struct Nodo* siguiente;
};

struct Nodo* cabeza =NULL;//como apenas empezamos debemos hacerlo con un nodo nulo como cabeza

void inserta(int valor)
{
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
//empezando por malloc, se usa para asignar memoria dinamica necesaria para alojar nuestro struct
//despues por struct nodo* se realiza una conversion de tipo de lo que nos dio malloc para que encaje con los struct
//basicamente en la linea anterior se llena nuestro nodo con datos vacios pero con lo justo para poder insertar datos
    nuevoNodo->dato=valor;
    nuevoNodo->siguiente=cabeza;
    cabeza=nuevoNodo;
}

void remueve(int valor)
{
    struct Nodo* actual=cabeza;
    struct Nodo* anterior=NULL;

    while(actual != NULL && actual->dato != valor)//va a parar hasta que sea el final de la lista o este en el valor dado
    {
        anterior = actual;
        actual=actual->siguiente;//mi nodo actual ahora es el que sigue
    }

    if(actual !=NULL)
    {
        if(anterior ==NULL)
        {
            cabeza = actual->siguiente;
        } else
        {
            anterior->siguiente = actual->siguiente;
        }

        free(actual);
    }
}

void imprimirLista()
{
    struct Nodo* actual = cabeza;

    while(actual != NULL)
    {
        printf("%d ", actual->dato);//solo imprime el dato
        actual = actual->siguiente;//su apuntador se dirige al siguiente
        //como si fuera un ++ en un array
    }

    printf("\n");
}

int main()
{
    inserta(1);//es el primer elemento a la derecha->
    inserta(2);
    inserta(3);
    inserta(4);
    inserta(5);
    inserta(6);
    inserta(2);
    inserta(1);//es el primer elemento a la izquierda<-
    imprimirLista();
    int udat;
    printf("dime el numero a eliminar: "); scanf("%d", &udat);
    remueve(udat);//dado que empieza desde izquierda a derecha, se elimina el primer numero a la izquierda
    imprimirLista();

return 0;
}

