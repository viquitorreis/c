#include <stdio.h>
#include <stdlib.h>

void quicksort(int array[], int tamanho);
void quicksort_recursivo(int array[], int inicio, int fim);
int partition(int array[], int inicio, int fim);
void swap(int *a, int *b);

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    int pares[1000];
    int impares[1000];
    int paresCount = 0;
    int imparesCount = 0;
    for (int i = 0; i < tamanho; ++i) {
        int temp;
        scanf("%d", &temp);
        if (temp % 2 != 0) {
            impares[imparesCount] = temp;
            imparesCount++;
        } else {
            pares[paresCount] = temp;
            paresCount++;
        }

    }

    quicksort(pares, paresCount);
    quicksort(impares, imparesCount);

    for (int i = 0; i < paresCount; ++i) {
        printf("%d ", pares[i]);
    }

    // Print odd numbers
    for (int i = 0; i < imparesCount; ++i) {
        printf(" %d ", impares[i]);
    }
    

    return 0;
}

void quicksort(int array[], int tamanho) {
    quicksort_recursivo(array, 0, tamanho - 1);
}

void quicksort_recursivo(int array[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo =  partition(array, inicio, fim); // pegando o indice do pivo    
        quicksort_recursivo(array, inicio, pivo - 1);
        quicksort_recursivo(array, pivo + 1, fim);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int inicio, int fim) {
    int pivo = array[fim];

    int i = inicio;
    for (int j = i; j < fim; j++) {
        if (array[j] <= pivo) {
            swap(&array[j], &array[i]);
            i++;
        }
    }

    swap(&array[i], &array[fim]);
    
    return i;
}
