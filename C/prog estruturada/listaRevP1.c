#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Faça um programa que leia um conjunto de números inteiros e que determine os números palíndromos. Palíndromos são
// números que têm o mesmo valor se lidos da esquerda para a direita ou da direita para a esquerda. Exemplo: 44, 232,
// 1661, etc. O final da leitura é indicado por um número negativo. Faça uma função que irá retornar para o programa
// principal se o número é palíndromo ou não.

int palindromo(int num){
    char n[10];
    sprintf(n, "%d", num);
    for (int i = 0; i <= strlen(n)/2; i++){
        if (n[i] != n[strlen(n)-1-i]){
            return 1;
        }
    }
    return 0;
}

// 2. Em uma competição de ginástica olímpica a nota é determinada por um painel de seis juízes. Cada um dos juízes
// atribui uma nota entre zero e dez para o desempenho do atleta. Para calcular a nota final, a nota mais alta e a nota
// mais baixa são descartadas e é calculada a média das quatro restantes. Escreva um programa que leia 6 notas entre
// zero e dez e calcule a média, de cada um dos 30 atletas, após o descarte da maior e da menor nota. Faça uma função
// que receba as seis notas lidas e que retorne para o programa principal a média calculada.

typedef struct {
    float nota1, nota2, nota3, nota4, notafinal;
} atleta;

void preenche(){
    atleta atletas[30];
    for (int i = 0; i < 30; i++){
        printf("\nNota 1, 2, 3, 4: ");
        scanf("%d %d %d %d", &atletas[i].nota1, &atletas[i].nota2, &atletas[i].nota3, &atletas[i].nota4);
    }
}

// 3. Escreva um programa para o seguinte problema: determinar se uma palavra A ocorre dentro de uma cadeia de
// caracteres B, mesmo que de forma não contígua. Fazer uma função que retorne 1 se A ocorrer dentro de B e zero,
// caso contrário. Exemplo:
// A = "lanterna"
// B = "No dia mais claro, na noite mais densa, o mal sucumbirá ante a minha presença."
// Resposta: A ocorre dentro de B:
// No dia mais claro, na noite mais densa, o mal sucumbirá ante a minha presença.

// 4. Faça um programa que leia dois números inteiros e que calcule o MDC (máximo divisor comum) entre eles. Crie uma
// função recursiva que retorne o valor do MDC, sabendo que:
// mdc(x, y) = y, se y ≤ x e x resto y = 0
// mdc(x, y) = mdc(y, x), se x < y
// mdc(x, y) = mdc(y, x resto y), caso contrário

// 5. Faça um programa que escreva uma série com os números inteiros compreendidos entre i e j. O intervalo entre os
// números deve ser k. Crie uma função recursiva imprimeSerie(i,j,k) que escreva os elementos desta série.

#include <stdio.h>

void serie(int i, int j, int k) {
if (i<=j) {
printf("%d\n", i);
serie(i+k,j,k);
}
}

int main(void) {

    int i,j,k;

    printf("Digite i: ");
    scanf("%d",&i);
    printf("Digite j: ");
    scanf("%d",&j);
    printf("Digite o intervalo k: ");
    scanf("%d",&k);
    serie(i,j,k);

    return 0;
}

// 6. Sabendo que o último caractere de uma string é ‘\0’, faça um programa que escreva a quantidade de caracteres desta
// string. Crie uma função recursiva que retorne esta quantidade de caracteres. Não é permitido o uso da função strlen.

// 7. Faça um programa que leia dois números inteiros A e B e que calcule o quociente da divisão de A por B. O programa
// deve conter uma função recursiva que retorne este valor, entretanto para este cálculo não deve ser usada nenhuma
// operação de divisão. Lembre-se que a divisão é conjunto de subtrações sucessivas.

// 8. Uma empresa que comercializa produtos alimentícios controla seu estoque diariamente. Faça um programa que leia a
// quantidade de estoque diário do mês passado e que calcule a média mensal em estoque. Determine também o maior e
// menor estoque lidos.

// 9. Escreva um programa que gere a tabuada de 1 até um valor n>0 na forma de uma tabela tal que, na posição da linha i e
// coluna j da tabela, deve-se encontrar o valor i*j.
// A tabuada deve ser guardada em uma matriz, e após a sua criação o programa deve dar ao usuário a opção de
// escolher um número X e ter a sua tabuada impressa. O programa encerra quando o usuário digitar um número
// negativo.

// 10. Faça um programa que leia um conjunto de dados sobre os N alunos de uma turma. Para cada aluno será lido o seu
// nome, suas 4 notas e seu ano de ingresso na faculdade. O programa deve calcular a média de cada aluno e indicar o
// nome do aluno que obteve a maior média (é possível que existam vários alunos). Deve ser usado um vetor de
// estruturas.

// 11. Faça um programa que leia dois vetores X e Y com números reais e escreva na tela as seguintes opções para o usuário:
// somar X e Y, subtrair Y de X, pesquisar um elemento em X e Y, mostrar X e Y e finalizar o programa. Devem ser
// criadas funções para: somar, subtrair, preencher, mostrar e procurar elemento.
