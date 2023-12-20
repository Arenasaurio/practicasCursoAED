#include <stdio.h>
#include <stdlib.h>
#include "treeimp.h"

//struct mom
struct node
{
    char data;
    struct node* left;
    struct node* right;

};
//Funtions
struct node* newNode(char data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data = data;
    //los pies o hijos del nodo son nulos porque no tiene, y para evitar un subdesborde
    node->left = NULL;
    node->right = NULL;
    return node;
}

