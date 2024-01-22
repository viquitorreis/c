#include <stdio.h>

void swap(int *a, int *b);
void quicksort(int array[], int tamanho);
void quicksort_recursivo(int array[], int inicio, int fim);
int partition(int array[], int inicio, int fim);

int main() {
    int a[] = { 46, 79, 36, 18, 73, 19, 67, 9, 90, 64 };
    int tamanho = sizeof(a) / sizeof(a[0]);

    quicksort(a, tamanho);

    return 0;
}

void swap(int * a, int*b) {
    int temp = *a;
    *a = *b;
    *b = *a;
}

void quicksort(int array[], int tamanho) {
    quicksort_recursivo(array, 0, tamanho - 1);
}

void quicksort_recursivo(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = partition(array, inicio, fim);
        quicksort_recursivo(array, indice_pivo - 1, fim); // lado esquerdo do pivo
        quicksort_recursivo(array, indice_pivo + 1, fim); // lado direito do pivo
    }
}

int partition(int array[], int inicio, int fim) {
    //           j
    //  46, 79, 36, 18, 73, 19, 67, 9, 90, [64]
    //      i

    int pivo = array[fim];

    int i = fim;

    for (int j = i; j < fim; ++j) {
        if (array[j] <= pivo) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[fim]);

    return i;
}


