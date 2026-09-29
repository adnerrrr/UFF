#include <stdlib.h>
#include <stdio.h>

typedef struct pilha{
    int info;
    struct pilha *prox;
}no;

no *push(no *topo, int elem){
    no *el;
    el = (no*)malloc(sizeof(no));
    el->info = elem;
    el->prox = topo;
    topo = el;
    return topo;
}

no *pop(no *topo){
    no *lixo;
    if (topo != NULL){
        lixo = topo;
        topo = topo->prox;
        free(lixo);
    }
    return topo;
}

int main(){
    no *topo;
    topo = NULL;
}