#include <stdio.h>

void swap(int *a, int *b);
void quicksort(int array[], int tamanho);
void quicksort_recursivo(int array[], int inicio, int fim);
void partition(int array[], int inicio, int fim);

int main() {
    int a[] = { 46, 79, 36, 18, 73, 19, 67, 9, 90, 64 };
    int tamanho = sizeof(a) / sizeof(a[0]);

    return 0;
}