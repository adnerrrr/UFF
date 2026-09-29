#include <stdlib.h>
#include <stdio.h>

#define MAX 10

//pilhas são listas que só podem ser incrementadas/decrementadas pelo topo (pense em pilha de pratos)
typedef struct pilha{
    int dado[MAX];
    int topo;
} pilha;

//adiciona o valor x ao topo da pilha caso a pilha não esteja cheia
void push(pilha *P, int x){
    if (P->topo < MAX-1){
        P->topo ++;
        P->dado[P->topo] = x;
    }
}

//remove o último valor da pilha caso ela seja maior do que 0
//o elemento continua na lista, mas o índice que indica o topo da lista é diminuido, oq indica que a pilha diminuiu
//ao incrementar um novo elemento esse valor é substituido
int pop(pilha *P){
    int num;
    if (P->topo >= 0){
        num = P->dado[P->topo];
        P->topo --;
    }
    return num;
}

int main(){
    pilha P;
    P.topo = -1;
}
