#include <stdio.h>
#include <stdlib.h>

struct nodito {
    char data;
    struct nodito* left;
    struct nodito* right;
};

struct nodito* newnodito(char data) {
    struct nodito* nodito = (struct nodito*)malloc(sizeof(struct nodito));
    nodito->data = data;
    nodito->left = NULL;
    nodito->right = NULL;
    return nodito;
}

void print(struct nodito *root, int cont) {
    if (root == NULL) {
        return;
    } else {
           print(root->right,cont+1);
           for(int i=0;i<cont;i++){
               printf("   ");
           }
            printf("->%c\n",root->data);
         print(root->left,cont+1);

    }
}

int main() {
    int cont=0;
    struct nodito *root = newnodito('/');
    root->left = newnodito('+');
    root->right = newnodito('*');
    root->left->left = newnodito('a');
    root->left->right = newnodito('b');
    root->right->left = newnodito('-');
    root->right->right = newnodito('e');
    root->right->left->left = newnodito('c');
    root->right->left->right = newnodito('d');
    printf("ARBOL\n");
    print(root, 0);

    return 0;
}
