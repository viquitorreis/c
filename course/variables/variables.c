#include <stdio.h>
#include <stdlib.h>

int main() {
    // variável para armazenar caracteres --> char
    char nomePersonagem[] = "Victor";
    int idadePersonagem = 24;

    printf("O nome do personagem é %s\n", nomePersonagem); // %s --> para printar strings
    printf("A idade do personagem é %d\n", idadePersonagem); // %d --> para printar inteiros

    idadePersonagem = 25;
    printf("%s vai fazer aniversário, e ficará com %d anos\n", nomePersonagem, idadePersonagem);
}