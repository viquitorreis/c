#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nomes com 3 ou mais palavras devem, deve-se abreviar o nome do meio
// -> Para abreviar o nome do meio, deve pegar somente a primeira letra e adicionar um ponto a ela
// Caso o nome tenha "da", "de", "do", "dos" ou "e", devem ser removidos
// EX: Victor Hugo dos Reis ---> Victor H. Reis

int main() {
    char buffer[201];
    
    scanf("%200[^\n]", buffer);

    char* name = (char*) malloc(strlen(buffer) + 1);;
    strcpy(name, buffer);

    char *espaco;
    espaco = strtok(name, " ");
    
    char* newName = (char*) malloc(strlen(buffer) + 1);;
    int count = 0;
    while (espaco != NULL) {
        count++;

        if (strcmp(espaco, "e") == 0 || strcmp(espaco, "dos") == 0 || strcmp(espaco, "do") == 0 || strcmp(espaco, "de") == 0 || strcmp(espaco, "da") == 0) {
            espaco = strtok(NULL, " "); //  movendo para o pŕoximo espaço
            continue;
        }

        newName = strcat(newName, name);

        espaco = strtok(NULL, " "); //  movendo para o pŕoximo espaço
    }

    printf("%s\n", newName);

    free(name); 
    free(newName); 
    return 0;
}