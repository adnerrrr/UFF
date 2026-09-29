#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 4. Faça um programa que leia dois números inteiros e que calcule o MDC (máximo divisor comum) entre eles. Crie uma
// função recursiva que retorne o valor do MDC, sabendo que:
    // mdc(x, y) = y, se y ≤ x e x resto y = 0
    // mdc(x, y) = mdc(y, x), se x < y
    // mdc(x, y) = mdc(y, x resto y), caso contrário

int mdc(int x, int y){
    if (y <= x)
        return y;
    else if (x < y)
        return mdc(y,x);
    else
        return mdc(y, x%y);
}

// 5. Faça um programa que escreva uma série com os números inteiros compreendidos entre i e j. O intervalo entre os
// números deve ser k. Crie uma função recursiva imprimeSerie(i,j,k) que escreva os elementos desta série.

void imprimeSerie(int i, int j, int k){
    if (i <= j){
        printf("%d ", i);
        imprimeSerie(i+k, j, k);
    }
}

// 1. Faça um programa que leia um conjunto de números inteiros e que determine os números palíndromos. Palíndromos são
// números que têm o mesmo valor se lidos da esquerda para a direita ou da direita para a esquerda. Exemplo: 44, 232,
// 1661, etc. O final da leitura é indicado por um número negativo. Faça uma função que irá retornar para o programa
// principal se o número é palíndromo ou não.

int palindromo(int num){
    char val[20];
    itoa(num, val, 10);
    int inicio = 0, fim = strlen(val) - 1; // -1 para tirar o caracter null do final
    while (inicio < fim){
        if (val[inicio] != val[fim])
            return 1;
        inicio ++;
        fim --;
    }
    return 0;
}
