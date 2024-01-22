// REMOVE DUPLICATES FROM SORTED ARRAY

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// HIPOTESE:
// PODEMOS RESOLVER ISSO COM UM HASHMAP

#include <stdio.h>
#include <stdlib.h> // biblioteca com malloc, alloc e free
#include <stdbool.h> // para usar variáveis boolean

// função que remove as duplicatas. Vai retornar um pointer para para o novo array que está sendo alocado no heap
// o tamanho do array vai ser dinamico, por isso precisamos passar um ponteiro para o novo tamanho
int *remove_duplicates(int arr[], int length, int *new_length);

int main() {
    int test[] = {1,2,3,4,5,6,7,8,2,1}

    return 0;
}

int *remove_duplicates(int arr[], int length, int *new_length) {
    // o maior array necessário é o array sem elementos duplicados
    int new_array = malloc(length * sizeof(int));

    // depois que descobrirmos quantas duplicatas tem no array, vamos saber qual o tamanho necessário pro array
    int unique_count = 0;
    // se o elemento não está no novo array, é porque é a primeira ocorrência dele

    for (int i = 0; i < length; ++i) {
        // vamos assumir que o elemento é unico inicialmente
        bool is_unique = true;
        
    }
}