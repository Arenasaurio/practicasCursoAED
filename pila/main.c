#include <stdio.h>
#define MAX_SIZE 100//da el valor maximo del vector

int stack[MAX_SIZE];
int top = -1;//indica que no tenemos una cima definida

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");//solo es para ver si esta lleno nuestro vector
        return;
    }

    top++;
    stack[top] = value;//mete el valor con el top aumentado
}

int pop() {
    if (top < 0) {
        printf("Error: Stack underflow\n");
        return -1;
    }//si se quiere eliminar algo que no existe

    int value = stack[top];
    top--;//solo disminuye el top, como tal no libera memoria
    return value;
}

int main() {
    push(3);
    push(5);
    push(7);
    push(9);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}
