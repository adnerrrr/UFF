#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int dado;
    struct lista *prox;
    struct lista *pre;
}lista;

// 1. Faça uma função recursiva que retorne o número de nós contidos em uma lista L. Considere que L é
// simplesmente encadeada, sem nó cabeça e não circular. Os elementos de L não estão
// necessariamente em ordem.

int contaNo(lista *L){
    if (L->prox == NULL)
        return 0;
    else
        return 1 + contaNo(L->prox);
}

// 3. Faça uma função recursiva que escreva se um determinado elemento pertence ou não a uma lista.
// Considere que L é simplesmente encadeada, sem nó cabeça e não circular.

int buscaElemento(lista *L, int num){
    if (L->dado == num)
        return 0;
    else if (L->prox == NULL)
        return 1;
    else
        return buscaElemento(L->prox, num);
}

// 5. Considere duas listas encadeadas L1 e L2, onde cada nó da lista possui duas partes: dado, que
// guarda um número inteiro e prox, que guarda o endereço do próximo nó. Para cada item abaixo, faça
// uma função que receba as duas listas como parâmetros e as concatene de acordo com as
// características especificadas.
// Para concatenar L1 com L2 basta juntar o final de L1 com o começo de L2, formando uma única lista
// com endereço inicial em L1.
    // a. L1 e L2 são simplesmente encadeadas, não circulares e sem nós cabeça;
lista *concatenaA(lista *L1, lista *L2){
    lista *aux = L1;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = L2;
    return L1;
}
    // b. L1 e L2 são simplesmente encadeadas, circulares e sem nós cabeça;
lista *concatenaB(lista *L1, lista *L2){
    lista *aux = L1;
    lista *aux2 = L2;
    while (aux->prox != L1)
        aux = aux->prox;
    while (aux2->prox != L2)
        aux2 = aux2->prox;
    aux->prox = L2;
    aux2->prox = L1;
    return L1;
}
    // c. L1 e L2 são simplesmente encadeadas, circulares e com nós cabeça;
lista *concatenaC(lista *L1, lista *L2){
    lista *aux = L1;
    lista *aux2 = L2;
    while (aux->prox != L1)
        aux = aux->prox;
    while (aux2->prox != L2)
        aux2 = aux2->prox;
    aux->prox = L2->prox;
    aux2->prox = L1;
    free(L2);
    return L1;
}
    // d. L1 e L2 são simplesmente encadeadas, não circulares e com nós cabeça;
lista *concatenaD(lista *L1, lista *L2){
    lista *aux = L1;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = L2->prox;
    free(L2);
    return L1;
}
    // e. L1 e L2 são duplamente encadeadas, circulares e com nós cabeça;
lista *concatenaE(lista *L1, lista *L2){
    lista *auxprox = L1;
    lista *aux2prox = L2;
    while (auxprox->prox != L1)
        auxprox = auxprox->prox;
    while (aux2prox->prox != L2)
        aux2prox = aux2prox->prox;
    L1->pre = aux2prox;
    aux2prox->prox = L1;
    auxprox->prox = L2->prox;
    L2->prox->pre = auxprox;
    free(L2);
    return L1;
}
//IGNOREI CASOS EM QUE L1 OU L2 SÃO VAZIOS