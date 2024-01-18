#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Note: The returned array must be malloced, assume caller calls free().

// 1 -> alocando variável global.
// Vamos realocar esse array a medida que percorrermos a arvore. OU seja, se tiver 4 elementos no array alocados, e acharmos mais 1,
// vamos aumentar a capacidade para 5 elementos

int* arr;
int size; // --> indica o tamanho de arr

// função helper para percorrer a árvore. Vai ser uma FUNÇÃO RECURSIVA
void inorder(struct TreeNode* node) {
    // base case
    if(!node) {
        return;
    }

    // indo para a esquerda primeiro
    inorder(node->left);

    // precisamos armazenar nosso nó atual. Para armazenar ele precisamos REALOCAR o tamanho de arr
    // aqui estamos pegando o ponteiro arr, e fazendo um outro ponteiro apontando pra um espaço na memória maior que o anterior
    arr = (int*)realloc(arr, sizeof(int)*++size); // ou seja, se era 4 antes, o ++size vai somar +1
    arr[size - 1] = node->val; // inserindo o valor do nó atual no array
    inorder(node->right); // fazendo a busca no nó da direita
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    size = 0; // a cada teste do judge precisamos reinicializar nossas variáveis globais
    arr = NULL;
    // NÃO PRECISAMOS USAR O FREE(arr) POIS NO ENUNCIADO FALA Q QUEM CHAMA ESTÁ FAZENDO FREE(arr)
    inorder(root);
    *returnSize = size;
    return arr; 
}

int main() {
    struct TreeNode root = {1, NULL, NULL};
    root.right = &(struct TreeNode){2, NULL, NULL};
    root.right->left = &(struct TreeNode){3, NULL, NULL};

    // arvore criada:
    //     1
    //      \
    //       2
    //      /
    //     3

    int returnSize;
    int* inTv = inorderTraversal(&root, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\n", inTv[i]);
    }
    free(inTv);
    return 0;
}