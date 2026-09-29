#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

// 1. Faça um programa que leia os nomes e as notas dos 60 alunos de uma turma e
// imprima, após a entrada de todos os dados, os nomes dos alunos aprovados.
// Considere que a média para aprovação é 6,0.

typedef struct {
    char nome[50];
    float nota;
} Aluno;

void aprovado(){
    Aluno turma[5];
    for (int i = 0; i < 5; i++){
        printf("\n nome: ");
        scanf("%s", &turma[i].nome);
        printf("\n nota: ");
        scanf("%.2f", &turma[i].nota);
    }
    for (int i = 0; i < 5; i++){
        if (turma[i].nota >= 6.00){
            printf("\n%s aprovado", turma[i].nome);
        }
    }
}

// 2. Considere um vetor que guarde 100 números reais. Faça um programa que
// preencha este vetor. Após o vetor preenchido multiplique seus valores ímpares
// por 3 e divida os valores pares por 2. Escreva o maior elemento do vetor.

float vetor[100];
void preenche(float vetor[100]){
    for (int i = 0; i < 100; i++){
        scanf("%f", &vetor[i]);
    }
}
void transforma(float vetor[100]){
    int aux;
    for (int i = 0; i < 100; i++){
        aux = (int)vetor[i];
        if (aux % 2 == 0){
            vetor[i] = vetor[i] / 2;
        }
        else{
            vetor[i] = vetor[i] * 3;
        }
    }
}
float maior(float vetor[100]){
    float maior = vetor[0];
    for (int i = 0; i < 100; i++){  
        if (vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}

// 3. Faça um programa que leia os N salários dos funcionários de uma empresa.
// Calcule a média salarial da empresa e escreva a quantidade de funcionários que
// possuem salário acima da média. 

void Salario(float salarios[N]){
    // preenche os salarios e calcula a media salarial
    float media = 0;
    for (int i = 0; i < N; i++){
        scanf("%f", &salarios[i]);
        media += salarios[i];
    }
    media /= N;
    // procura o numero de funcionarios com salario acima da media
    int total = 0;
    for (int i = 0; i < N; i++){
        if (salarios[i] > media){
            total += 1;
        }
    }
    printf("O total de funcionarios com salario acima da media e %d", total);
}

// 4. Faça um programa que preencha um vetor de N posições com os N primeiros
// termos de uma série de Fibonacci (0 1 1 2 3 5 8 13 21 34...). Após preenchido o
// vetor, verifique se um determinado número informado pelo usuário pertence ou
// não ao vetor.

void fib(int m){
    int lista[m];
    lista[0] = 0;
    lista[1] = 1;
    for (int i = 2; i < m; i++){
        lista[i] = lista[i - 1] + lista[i - 2];
    }
    int num;
    scanf("%d", &num);
    for (int i = 0; i < m; i++){
        if (lista[i] == num){
            printf("pertence");
            break;
        }
    }
}

// 5. Faça um programa que preencha uma matriz M10x5 com números inteiros. Após
// preencher a matriz, crie uma segunda matriz que seja a transposta de M. Ao
// final, escreva a matriz Transposta.


// 6. Faça um programa que preencha uma matriz M5x5 com números reais. Após
// preencher a matriz:
// a) Verifique se ela é simétrica.

void simetria(float matriz[5][5]){
    int sim = 1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (matriz[i][j] != matriz[j][i]){
                sim = 0;
                break;
            }
        }
        if (sim == 0){
            break;
        }
    }
    if (sim == 0){
        printf("nao simetrica");
    }
    else{
        printf("simterica");
    }
}

// b) Imprima a soma dos elementos da diagonal principal.

void imprimePrincipal(float matriz[5][5]){
    float s = 0;
    for (int i = 0; i < 5; i++){
        s += matriz[i][i];
    }
    printf("%f", s);
}

// c) Imprima a soma dos elementos da diagonal secundária.

void imprimeSecundaria(float matriz[5][5]){
    float s = 0;
    for (int i = 0; i < 5; i++){
        s += matriz[i][4 - i];
    }
    printf("%f", s);
}

int main() {

}