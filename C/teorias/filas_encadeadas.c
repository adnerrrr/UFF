#include <stdlib.h>
#include <stdio.h>

typedef struct fila{
    int info;
    struct fila *prox;
}no;

void insereElemento(no **inicio, int elem, no **fim){
    no *el;
    el = (no*)malloc(sizeof(no));
    el->info = elem;
    el->prox = NULL;
    if ((*inicio) == NULL){
        (*inicio) = el;
    }
    else{
        (*fim)->prox = el;
    }
    (*fim) = el;
}

no *removeElemento(no *inicio){
    no *lixo;
    if (inicio != NULL){
        lixo = inicio;
        inicio = inicio->prox;
        free(lixo); 
    }
    return inicio;
}

int main(){
    no *inicio, *fim;
    inicio = NULL;
    fim = NULL;
}