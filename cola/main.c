#include <stdio.h>
#include <stdlib.h> //operaciones de punteros
//plantilla Nodo
struct nodo{
    int dato;
    struct nodo *next; //liga
};
struct nodo *front=NULL, *rear=NULL; //Nuevos punteros vacios
//funciones prototipo
void EnQueue(int);//encolar o insertar
void DeQueue();//desencolar o eliminar
void print();//imprimir

int main() {
    int opc, val;
    while (1) {
        printf("\n-----Menu-----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Imprimir\n");
        printf("Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Valor: ");
                scanf("%d", &val);
                EnQueue(val);
                break;
            case 2:
                DeQueue();
                break;
            case 3:
                print();//imprimir elementos en cola
                break;
            case 4:
                return 0;
        }
    }
}

    //implementaciones
    void EnQueue(int val) {
        struct nodo *newNode;
        newNode = (struct nodo *)malloc(sizeof(struct nodo));
        newNode->dato = val;
        newNode->next = NULL;
        if(front==NULL)// preguntar si esta vacio
            front=rear=newNode;//hay un unico elemento
        else{//ya hay elementos en cola
            rear->next = newNode; //esta ligando al nuevo nodo
            rear = newNode;//rear ahora sera el nuevo nodo
        }
        printf("\nDatos Agregados\n");
    }

    void DeQueue(){
        if (front==NULL)
            printf("\nNo hay elementos en cola\n");
        else{
            struct nodo *temp = front;//respaldo de front
            front = front->next;//se movio front al siguiente
            printf("\nSe elimino el valor %d\n", temp->dato);
            free(temp);//se libera temp(viejo front)
        }
    }
    void print(){
        if(front==NULL)
            printf("\nNo hay elementos");
        else{
            struct nodo *temp=front; //inicio
            while(temp!=NULL){
                printf("%d |\n", temp->dato);
                //actualizacion de puntero temporal
                temp = temp->next;
            }
        }
    }
