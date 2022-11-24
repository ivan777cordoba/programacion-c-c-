#include <stdio.h>
/*
Técnica de ordenación Quicksort
*/
int main() {
    void Ordenar(int array[], int inicio, int fin, int n);
    void ImprimirArray(int array[], int n);

    // Leer dimensión del arreglo
    int n;
    printf("Introduzca la cantidad de numeros a ordenar: ");
    scanf("%d", &n);
    int array[n];
    // Leer numeros a ordenar
        for (int i=0; i<n; i++) {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &array[i]);
    }
    // Imprime el arreglo antes de comenzar el ordenamiento
    printf("\nArreglo sin ordenar: \n");
    ImprimirArray(array, n);
    // Ordena el arreglo
    printf("\nProceso de ordenamiento: \n");
    Ordenar(array, 0, n-1, n);
    // Imprime el arreglo completamente ordenado
    printf("Arreglo ordenado: \n");
    ImprimirArray(array, n);
    }
void Ordenar(int array[], int inicio, int fin, int n){
    int pivote, izq, der;
    void ImprimirArray(int array[], int n);
    // Caso base
    if(inicio < fin){
        // Imprime el arreglo en el paso en el que se encuentra
        printf("Arreglo en el paso actual:\n");
        ImprimirArray(array, n);

        pivote = array[inicio];
        izq = inicio;
        der = fin;
        // Separa los elementos menores al pivote a la izquierda y los elementos mayores a la derecha
        while (izq < der) {
            while (der>izq && array[der]>pivote) {
                der--;
            }
            if (der > izq) {
                array[izq] = array[der];
                izq++;
            }
            while (izq< der && array[izq] < pivote) {
                izq++;
            }
            if (izq<der) {
                array[der] = array[izq];
                der--;
            }
        }
        array[der] = pivote;
        // Imprime pivote, numeros a la izquiera y derecha del pivote
        printf("Pivote: %d \n", pivote);
        printf("Numeros a la izquierda del pivote: ");
        for(int i=0; i<der; i++){
            printf("%d ", array[i]);
        }
        printf("\n");
        printf("Numeros a la derecha del pivote: ");
        for(int i=der+1; i<n; i++){
            printf("%d ", array[i]);
        }
        printf("\n\n");
        // Se utiliza recursividad para ordenar los elementos de la izquiera y los elementos de la derecha
        Ordenar(array, inicio, der - 1, n);
        Ordenar(array, der + 1, fin, n);
        }
}
void ImprimirArray(int array[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    }
