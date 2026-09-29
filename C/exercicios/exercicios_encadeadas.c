/* 1 Faça um programa que:
Crie uma lista encadeada L com números inteiros.
Os números devem ser inseridos na lista em ordem crescente até que o usuário digite um número negativo.
A lista não deve possuir números repetidos.
Ao final do programa, imprima a lista.
Devem ser criadas as funções de buscaElemento, insereElemento e ImprimeLista */

#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}lista;

int buscaElemento(lista *L, int elem, lista **pre){
    lista *aux, *preL;
    aux = L;
    preL = NULL;
    while (aux != NULL && elem > aux->info){
        preL = L;
        aux = L->prox;
    }

    (*pre) = preL;

    if (aux != NULL && elem == aux->info){
        printf("Ja esta na lista");
        return 1;
    }
    return 0;
}

lista *insere(lista *L, int elem){
    lista *el, *pre;
    el = (lista*)malloc(sizeof(lista));
    if (!buscaElemento(L, elem, &pre)){
        el->info = elem;
        if (pre == NULL){
            el->prox = L;
            L = el;
        }
        else{
            el->prox = pre->prox;
            pre->prox = el;
        }
    }
    return L;
}

void imprimeLista(lista *L){
    if (L != NULL){
        printf("|%d|", L->info);
        imprimeLista(L->prox);
    }
    else
        printf("\n");
}

int main_ex1(){
    int op, num = 0;
    lista *L;
    L = NULL;
    while (op != 5){
        printf("\n[1]Imprimir a Lista\n[2]Inserir na Lista\n[3]Buscar na Lista\n[4]Remover da Lista\n[5]Sair\n-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                imprimeLista(L);
                break;
            case 2:
                printf("\nQual numero deseja inserir? ");
                scanf("%d", &num);
                L = insere(L, num);
                break;
            case 3:
                printf("\nVai ficar querendo");
                break;
            case 4:
                op = 5;
                break;
            case 5:
                break;
        }
    }
    op = 1;
    return 0;
}

/*2. Faça um programa que:
Crie uma pilha encadeada com números inteiros.
Os números devem ser inseridos na pilha até que o usuário digite um número negativo.
Ao final do programa, imprima a pilha.
Devem ser criadas as funções push e pop.*/

typedef struct pilha{
    int info;
    struct pilha *prox;
}pilha;

pilha *push(pilha *P, int elem){
    pilha *el;
    el = (pilha*)malloc(sizeof(pilha));
    el->info = elem;
    el->prox = P;
    P = el;
    return P;
}

pilha *pop(pilha *P){
    pilha *lixo;
    if (P != NULL){
        lixo = P;
        P = P->prox;
        free(lixo);
    }
    return P;
}

void imprimePilha(pilha *P){
    if (P != NULL){
        printf("|%d|", P->info);
        imprimePilha(P->prox);
    }
}

int main_ex2(){
    int op, num;
    pilha *P;
    P = NULL;
    while (op != 5){
        printf("\n[1]Imprimir a Pilha\n[2]Inserir na Pilha\n[3]Buscar na Pilha\n[4]Remover da pilha\n[5]Sair\n-> ");
        scanf("%d", &op);
        switch (op){
            case 1:
                printf("\n");
                imprimePilha(P);
                break;
            case 2:
                printf("\nQual numero deseja inserir? ");
                scanf("%d", &num);
                P = push(P, num);
                break;
            case 3:
                printf("\nVai ficar querendo");
                break;
            case 4:
                P = pop(P);
                break;
            case 5:
                break;
        }
    }
    op = 1;
    return 0;
}

int main(){
    int ex = 0;
    while (ex != 3){
        printf("Escolha o exercicio: \n");
        printf("[1] Listas \n");
        printf("[2] Pilhas \n");
        printf("[3] Sair \n");
        printf("-> ");
        scanf("%d", &ex);
        switch(ex){
            case 1:
                main_ex1();
                break;
            case 2:
                main_ex2();
                break;
            case 3:
                break;
        }
    }
}