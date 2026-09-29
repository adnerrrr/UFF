#include <stdlib.h>
#include <stdio.h>

#define MAX 10

// filas são listas nas quais o elemento entra no final e sai do início
typedef struct fila{
    int dados[MAX];
    int inicio;
    int topo;
    int total;
}fila;

//o elemento é inserido no final. é importante checar o final da lista pois ela pode estar no começo da lista
//como o comportamento é de uma fila, os elementos do inicio vão embora e sobram o do final
//para evitar isso, tratamos a fila de maneira cíclica, sempre recalculando o topo dela
void insere(fila *F, int x){
    if (F->total < MAX){
        F->dados[F->topo] = x;
        F->topo ++;
        F->topo = F->total % MAX;
        F->total ++;
    }
}

//o elemento é removido do início. a mesma lógica de ciclicidade da inserção é aplicada aqui
// int remove(fila *F){
//     int num;
//     if (F->total > 0){
//         num = F->dados[F->inicio];
//         F->total --;
//         F->inicio ++;
//         F->inicio = F->inicio % MAX;
//     }
//     return num;
// }

int main(){
    fila F;
    F.inicio = 0;
    F.topo = 0;
    F.total = 0;
}