// Prueba del algoritmo de huffman para calcular los codigos
#include <stdio.h>
#include <stdlib.h>
 

#define Maximo 100
 
// A Huffman tree node
struct MinHeapNode {
 
    // caracter del input
    char data;
 
    // Frecuencia 
    unsigned freq;
 
    // Hijos derecho e izquierdo del nodo
    struct MinHeapNode *izquierdo, *derecho;
};
 

struct MinHeap {
 
    unsigned size;
    unsigned capacidad;
    struct MinHeapNode** array;
};
 /*
 Structura que crea un nuevo nodo, 
 dados el caracter y la frecuencia del caracter
 */

struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));
 
    temp->izquierdo = temp->derecho = NULL;
    temp->data = data;
    temp->freq = freq;
 
    return temp;
}
 
// Funcion para crear un nodo de dicha capacidad
struct MinHeap* createMinHeap(unsigned capacidad)
{
    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));
 
    // el tamaño actual es 0
    minHeap->size = 0;
 
    minHeap->capacidad = capacidad;
 
    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->
 capacidad * sizeof(struct MinHeapNode*));
    return minHeap;
}
 
// Funcion para intercambiar 2 nodos
void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b)
 
{
 
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
 
// Funcion estandar del heap 
void minHeapify(struct MinHeap* minHeap, int idx)
 
{
 
    int smallest = idx;
    int izquierdo = 2 * idx + 1;
    int derecho = 2 * idx + 2;
 
    if (izquierdo < minHeap->size && minHeap->array[izquierdo]->
freq < minHeap->array[smallest]->freq)
        smallest = izquierdo;
 
    if (derecho < minHeap->size && minHeap->array[derecho]->
freq < minHeap->array[smallest]->freq)
        smallest = derecho;
 
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
 
// Funcion para chequear si el tamaño del heap es 1
int isSizeOne(struct MinHeap* minHeap)
{
 
    return (minHeap->size == 1);
}
 
// Funcion para extraer el valor minimo del nodo del arbol
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
 
{
 
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1];
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return temp;
}
 
// Funcion para insertar un nuevo nodo al arbol
void insertMinHeap(struct MinHeap* minHeap,
                   struct MinHeapNode* minHeapNode)
 
{
 
    ++minHeap->size;
    int i = minHeap->size - 1;
 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
 
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
 
    minHeap->array[i] = minHeapNode;
}
 
// Funcion para construir el heap
void buildMinHeap(struct MinHeap* minHeap)
 
{
 
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 
// Funcion para imprimir un array de tamaño n
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
 
    printf("\n");
}
 
// Funcion para chequear si el nodo es una hoja
int isLeaf(struct MinHeapNode* root)
 
{
 
    return !(root->izquierdo) && !(root->derecho);
}
 
// Crea un heap de capacidad igual al tamaño e inserta
// todos los caracteres de data [] in el heap. 
// Inicialmente el tamaño del heap es igual a la capacidad.
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
 
{
 
    struct MinHeap* minHeap = createMinHeap(size);
 
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
 
    minHeap->size = size;
    buildMinHeap(minHeap);
 
    return minHeap;
}
 
// Funcion para crear el arbol de huffman
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
 
{
    struct MinHeapNode *izquierdo, *derecho, *top;
 
    // Paso 1: Crear un heap de capacidad igual al tanaño. Inicialmente, hay modos igual al tamaño
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
 
    // Iteracion while para que el heap no se convierta en 1
    while (!isSizeOne(minHeap)) {
 
        // Paso 2: Extraer las 2 frecuencias menores del heap
        izquierdo = extractMin(minHeap);
        derecho = extractMin(minHeap);
 
        // Paso 3:  Crear un nodo interno con frecuencia igual a la suma de los 2 frecuencias de los nodos
        // Hacer los 2 nodos extraidos respectivamente como el izquierdo y derecho del nuevo nodo
        // Agregar este nodo al heap
        top = newNode('$', izquierdo->freq + derecho->freq);
 
        top->izquierdo = izquierdo;
        top->derecho = derecho;
 
        insertMinHeap(minHeap, top);
    }
 
    // Paso 4: El nodo restante es la raiz y el arbol esta completo
    return extractMin(minHeap);
}
 
// Imprime el codigo huffman desde la raiz del arbol de huffman
// Utiliza arr [] para guardar los codigos
void printCodes(struct MinHeapNode* root, int arr[], int top)
 
{
 
    if (root->izquierdo) {
 
        arr[top] = 0;
        printCodes(root->izquierdo, arr, top + 1);
    }
 
    if (root->derecho) {
 
        arr[top] = 1;
        printCodes(root->derecho, arr, top + 1);
    }
 
    if (isLeaf(root)) {
 
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
 /*
 La funcion principal que construye un arbol de huffman e imprime el codigo
 creado por el arbol 
 */
void CodigoHuffman(char data[], int freq[], int size)
 
{
    // Construye el arbol de huffman
    struct MinHeapNode* root
        = buildHuffmanTree(data, freq, size);
 
    // Imprime el codigo de huffman utilizando
    // el arbol de huffman construido arriba
    int arr[Maximo], top = 0;
 
    printCodes(root, arr, top);
}
 //Funcion main, que de aqui asignamos los arreglos de prueba
int main()
{
 	//Recibe arreglos con las letras y los numeros
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 7, 9, 12, 13, 16, 45 };
    //Calcula el tamaño 
 
    int size = sizeof(arr) / sizeof(arr[0]);
 	//Llama a la funcion de huffman
    CodigoHuffman(arr, freq, size);
 
    return 0;
}