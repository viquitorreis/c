#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char **a, char **b);
void quicksort(char *array[], int tamanho);
void quicksort_recursivo(char *array[], int inicio, int fim);
int partition(char *array[], int inicio, int fim);
void print_array(char *array[], int tamanho);

int main() {
    char* arrStr[] = { "amora", "zeus""banana", "morango", "laranja", "banana", "melao", "melancia" };
    // char* arrStr[] = { "x", "a", "z", "y", "h"};
    int tamanho = sizeof(arrStr) / sizeof(arrStr[0]);

    quicksort(arrStr, tamanho);

    printf("Array ordenado: ");
    print_array(arrStr, tamanho);

    ////////////////////
    int maxWords;
    scanf("%d", &maxWords);
    char *words[maxWords];

    for (int i = 0; i < maxWords; i++) {
        words[i] = (char*)malloc(50 * sizeof(char)); // max de 50 caracteres
        scanf("%s", words[i]);
    }
    int sizeOfArray = sizeof(words) / sizeof(words[0]);

    quicksort(words, sizeOfArray);

    printf("Array ordenado 2: ");
    print_array(words, sizeOfArray);

    return 0;
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(char *array[], int tamanho) {
    quicksort_recursivo(array, 0, tamanho - 1);
}

void quicksort_recursivo(char *array[], int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = partition(array, inicio, fim);
        quicksort_recursivo(array, inicio, indice_pivo - 1); // lado esquerdo do pivo
        quicksort_recursivo(array, indice_pivo + 1, fim); // lado direito do pivo
    }
}

int partition(char *array[], int inicio, int fim) {
    char* pivo = array[fim];

    int i = inicio;

    for (int j = i; j < fim; ++j) {
        if (strcmp(array[j], pivo) < 0) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[fim]);

    return i;
}

void print_array(char *array[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("%s ", array[i]);
    }
    printf("\n");
}
