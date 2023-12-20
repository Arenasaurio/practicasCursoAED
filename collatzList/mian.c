
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    long data;
    struct node* next;
} node;

node* head = NULL;

void add_node(long n) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = n;
    new_node->next = head;
    head = new_node;
}

int collatz(long n) {
    int count = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        add_node(n);
        count++;
    }
    return count;
}

int main() {
    int max_count = 0;
    int max_num = 0;
    for (int i = 1; i < 1000000; i++) {
        head = NULL;
        add_node(i);
        int count = collatz(i);
        if (count > max_count) {
            max_count = count;
            max_num = i;
        }
    }
    printf("El número que produce la secuencia de Collatz más larga es %d, con una longitud de %d.\n", max_num, max_count);
    return 0;
}
