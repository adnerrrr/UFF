#include <stdio.h>
#include <stdlib.h>

#define N 3

// dada uma matriz N*N, faça uma função que transforme a matriz em um vetor com cada linha sendo um no de uma lista e print cada uma delas
//  ex: 
//   | 1 2 3 |           □-> [1□]-> [2□]-> [3□]-> NULL
//   | 4 5 6 |    ->     □-> [4□]-> [5□]-> [6□]-> NULL
//   | 7 8 9 |           □-> [7□]-> [8□]-> [9□]-> NULL

typedef struct no{
    int dado;
    struct no *prox;
}no;

void questao(int matriz[N][N]){
    no *vet[N];
    vet[N] = (no*)malloc(sizeof(no));
    for (int i = 0; i<N;i++){
        no *dados[N];
        for (int j=0; j<N;j++){
            no *elemento;
            elemento = (no*)malloc(sizeof(no));
            elemento->dado = matriz[i][j];
            elemento->prox = NULL;
            dados[j] = elemento;
        }
        for (int l=1; l<N; l++){
            dados[l-1]->prox = dados[l];
        }
        vet[i] = dados[0];
    }
    for (int i=0; i<N;i++){
        no *aux = vet[i];
        for (int j = 0; j<N; j++){
            printf("%d -> ", aux->dado);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

void gabarito(int matriz[N][N]){
    no *vet[N], *aux;
    vet[N] = (no*)malloc(sizeof(no));
    for (int i = 0; i<N;i++){
        vet[i] = (no*)malloc(sizeof(no));
        aux = vet[i];
        for (int j=0; j<N;j++){
            aux->dado = matriz[i][j];
            if (j != N-1){
                aux->prox = (no*)malloc(sizeof(no));
                aux = aux->prox;
            }
            else
                aux->prox = NULL;
        }
    }
    for (int i=0; i<N;i++){
        no *aux = vet[i];
        for (int j = 0; j<N; j++){
            printf("%d -> ", aux->dado);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

int main(){
    int matriz[N][N];
    int num = 0;
    for (int a = 0; a<N; a++){
        for (int b=0; b<N; b++){
            num++;
            matriz[a][b] = num;
        }
    }
    gabarito(matriz);
}
