#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int dado;
    struct pilha *prox;
}pilha;

typedef struct fila{
    int dado;
    struct fila *prox;
    // precisa iniciar o inicio e o final
}fila;

// 1. Faça uma função que receba uma pilha P como parâmetro e que escreva todos os seus elementos.
// Considere uma pilha de números inteiros. Considere alocação encadeada dinâmica.

void escrevePilha(pilha *P){
    if (P != NULL)
        printf("%d\n", P->dado);
        escrevePilha(P->prox);
}
