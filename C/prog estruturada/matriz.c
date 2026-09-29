#include <stdio.h>
#include <string.h>

/* Crie uma matriz NxN que guarde numeros inteiros 
- faca uma funcao p preencher a matriz
- faca uma funcao que verifique se a matriz e simetrica
- faca uma funcao recursiva que receba o maior elemento da diagonal principal (X) e que escreva os X primeiros num > 0 em ordem crescente*/

void preenche(int N, int matriz[N][N]) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++){
            printf("Digite o numero [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int simetria(int N, int matriz[N][N]) {
    int sim = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (matriz[i][j] == matriz[j][i]) {
                sim = 0;
            }
            else {
                sim = 1;
                return sim;
                break;
            }
        }
    }
    return sim;
}

void escreve(int N, int matriz[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int maior(int N, int matriz[N][N]){
    int valor = matriz[0][0];
    for (int i = 0; i < N; i++){
        if (matriz[i][i] > valor){
            valor = matriz[i][i];
        }
    }
    return valor;
}

void printmaior(int N){
    if (N > 0){
        printmaior(N-1);
        printf("%d ", N);
    }
}

int main(void) {
    int N;
    printf("Digite o tamanho da matriz NxN: ");
    scanf("%d", &N);
    int matriz[N][N];
    preenche(N, matriz);
    escreve(N, matriz);
    if (simetria(N, matriz) == 1) {
        printf("Nao eh simetrica\n");
    }
    else{
        printf("Eh simetrica\n");
    }
    printmaior(maior(N, matriz));
}