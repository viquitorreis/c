#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void quicksort(int array[], int tamanho);
void quicksort_recursivo(int array[], int inicio, int fim);
int partition(int array[], int inicio, int fim);
void print_array(int array[], int tamanho);

int main() {
    int a[] = { 46, 79, 36, 18, 73, 19, 67, 9, 90, 64 };
    int tamanho = sizeof(a) / sizeof(a[0]);

    quicksort(a, tamanho);

    printf("Array ordenado: ");
    print_array(a, tamanho);
    printf("\n");

    // lendo o input do user
    int tamanhoArr;
    scanf("%d", &tamanhoArr);

    int arrNums[tamanhoArr];

    for (int i = 0; i < tamanhoArr; i++) {
        scanf("%d", &arrNums[i]);
    }

    quicksort(arrNums, tamanhoArr);

    printf("Array ordenado 2: ");
    print_array(arrNums, tamanhoArr);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int array[], int tamanho) {
    quicksort_recursivo(array, 0, tamanho - 1);
}

void quicksort_recursivo(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = partition(array, inicio, fim);
        quicksort_recursivo(array, inicio, indice_pivo - 1); // lado esquerdo do pivo
        quicksort_recursivo(array, indice_pivo + 1, fim); // lado direito do pivo
    }
}

int partition(int array[], int inicio, int fim) {
    //           j
    //  46, 79, 36, 18, 73, 19, 67, 9, 90, [64]
    //      i

    // DEPOIS COLOCAR O PIVO DINAMICO / RANDOM

    int pivo =  array[fim];

    int i = inicio;

    for (int j = i; j < fim; ++j) {
        if (array[j] <= pivo) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    printf("Fim de recursão em partition: ");
    print_array(array, 10);
    swap(&array[i], &array[fim]);

    return i;
}

void print_array(int array[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}