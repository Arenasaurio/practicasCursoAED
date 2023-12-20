#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Function to allocate a new tree node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to print Huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, char* str) {
    if (!root)
        return;

    if (root->data != '$')
        printf("%c: %s\n", root->data, str);

    char str0[100];
    strcpy(str0, str);
    strcat(str0, "0");
    printCodes(root->left, str0);

    char str1[100];
    strcpy(str1, str);
    strcat(str1, "1");
    printCodes(root->right, str1);
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    struct MinHeapNode* minHeap[size];
    for (int i = 0; i < size; ++i)
        minHeap[i] = newNode(data[i], freq[i]);

    // Sort minHeap array using frequency
    for (int i = 0; i < size-1; i++)
        for (int j = 0; j < size-i-1; j++)
            if (minHeap[j]->freq > minHeap[j+1]->freq) {
                struct MinHeapNode* temp = minHeap[j];
                minHeap[j] = minHeap[j+1];
                minHeap[j+1] = temp;
            }

    // Iterate while size of heap doesn't become 1
    while (size != 1) {
        left = minHeap[0];
        right = minHeap[1];

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node.
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        // Add this node to the min heap
        // '$' is a special value for internal nodes, not used
        for (int i = 0; i < size-1; i++)
            minHeap[i] = minHeap[i+2];

        minHeap[size-2] = top;

        // Sort minHeap array using frequency
        for (int i = 0; i < size-1; i++)
            for (int j = 0; j < size-i-2; j++)
                if (minHeap[j]->freq > minHeap[j+1]->freq) {
                    struct MinHeapNode* temp = minHeap[j];
                    minHeap[j] = minHeap[j+1];
                    minHeap[j+1] = temp;
                }

        size--;
    }

    // Print Huffman codes using the Huffman tree built above
    char str[100] = "";
    printCodes(minHeap[0], str);
}

void almacenarLetras(char* str, char* letras) {
    int hash[MAX_CHAR] = {0};
    int index = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char temp = str[i];
        if(temp >= 'A' && temp <= 'Z') {
            temp += 'a' - 'A';
        }
        if (hash[temp] == 0) {
            letras[index] = temp;
            index++;
            hash[temp]++;
        }
    }
    letras[index] = '\0';
}

// Función para contar las repeticiones de cada letra en la cadena original
void contarRepeticiones(char* str, char* letras) {
    int count[MAX_CHAR] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        char temp = str[i];
        if(temp >= 'A' && temp <= 'Z') {
            temp += 'a' - 'A';
        }
        count[temp]++;
    }

    // Ordenar las letras por frecuencia de menor a mayor
    for (int i = 0; letras[i] != '\0'; i++) {
        for (int j = i + 1; letras[j] != '\0'; j++) {
            if (count[letras[i]] > count[letras[j]]) {
                char temp = letras[i];
                letras[i] = letras[j];
                letras[j] = temp;
            }
        }
    }

    printf("Caracter: Frecuencia\n");
    for (int i = 0; letras[i] != '\0'; i++) {
        if(letras[i]=='\n')
            continue;
        printf("%c: %d\n", letras[i], count[letras[i]]);
    }
}



// Driver program to test above functions
int main() {
    char arr[] = {'r','s','l','o'};
    int freq[] = {1,1,2,3};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    FILE *file = fopen("Frase.txt", "r");  // Abre el archivo en modo de lectura
    if (file == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    char str[100];  // Asegúrate de que la cadena sea lo suficientemente grande
    if (fgets(str, sizeof(str), file) != NULL) {
        printf("La línea leída del archivo es: %s\n", str);
    } else {
        printf("No se pudo leer la línea del archivo\n");
    }

    fclose(file);  // Cierra el archivo

    char letras[MAX_CHAR];

    almacenarLetras(str, letras);
    contarRepeticiones(str, letras);



    return 0;
}

