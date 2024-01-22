#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Checando se palavras são palindromos

int main() {
    char buffer[1001];

    scanf("%1001[^\n]", buffer);

    char* palindromo = (char*) malloc(strlen(buffer) + 1);

    // strcpy(destino, origem)
    strcpy(palindromo, buffer);
    printf("%s\n", palindromo);

    int size = strlen(palindromo) - 1;
    int start = 0;

    while (size > start) {
        if (palindromo[start++] != palindromo[size--]) {
            printf("Não é palíndromo, %s\n", palindromo);
            break;
        }
    }

    return 0;
}