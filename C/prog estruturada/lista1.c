#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 1. Faça um programa que leia 3 valores reais e que informe se eles formam um triângulo. Caso seja
// possível formar o triângulo indique se este é equilátero, isósceles ou escaleno.

void triangulo(int a, int b, int c){
    if ((a <= b + c) && (b <= a + c) && (c <= b + a)){
        if ((a == b) && (b == c)){
            printf("Equilatero");
        }
        else if(((a == b) && (a != c)) || ((a == b) && (a != b)) || ((c == b) && (a != c))){
            printf("Isosceles");
        }
        else{
            printf("Escaleno");
        }
    }
    else{
        printf("nao");
    }
}

// 2. Faça um programa que leia dois números inteiros e que calcule e mostre a soma e a multiplicação
// dos dois números e a divisão e a subtração do primeiro pelo segundo. Caso o segundo número
// digitado seja zero, o programa deve informar ao usuário que a operação de divisão é impossível.

void opera(float a, float b){
    printf("soma: %.2f \n", a+b);
    printf("produto: %.2f \n", a*b);
    printf("diferenca: %.2f \n", a-b);
    if (b == 0){
        printf("por 0 nao pode seu bosta");
    }
    else{
        printf("divisao: %.2f", a/b);
    }
}

// 3. Faça um programa que leia a idade de um nadador e que calcule e mostre a sua categoria seguindo
// as regras:
// • Categoria Baby: até 4 anos
// • Categoria Infantil: 5 – 10 anos
// • Categoria Juvenil: 11 – 17 anos
// • Categoria Máster: A partir de 18 anos

void categoria(int idade){
    if (idade <= 4){
        printf("baby");
    }
    else if (idade <= 10){
        printf("infantil");
    }
    else if (idade <= 17){
        printf("juvenil");
    }
    else{
        printf("master");
    }
}

// 4. Faça um programa que leia o preço de um produto, calcule o seu aumento e mostre a sua
// classificação.
// • Se o preço for menor ou igual a 50, o produto receberá um aumento de 5%
// • Se o preço for maior do que 50 e menor ou igual a 100, o aumento será de 10%
// • Se o preço for maior do que 100, o aumento será de 15%
// A classificação do produto deve ser:
// • Barato: até 80 reais (inclusive)
// • Normal: entre 80 reais e 120 reais (inclusive)
// • Caro: entre 120 reais e 200 reais (inclusive)
// • Muito Caro: maior do que 200 reais

// 5. Faça um programa que leia a altura e o sexo de uma pessoa e escreva o seu peso ideal, utilizando as
// seguintes fórmulas:
// • para homens: (72,7 * altura) – 58,0
// • para mulheres: (62,1 * altura) – 44,7

// 6. Faça um programa que leia um valor inteiro e que informe se este valor é par ou impar.

// 7. Faça um programa que leia a quantidade de horas aula dadas por dois professores e o valor por
// hora recebido por cada um. Mostrar na tela qual dos professores tem salário total maior.

// 8. Faça um programa que leia o número de eleitores de um município, o número de votos brancos,
// nulos e validos. Calcule e escreva o percentual que cada um representa em relação ao total de
// eleitores.

// 9. A prefeitura da “Terra do Nunca” vai realizar suas eleições em urnas eletrônicas, sendo 3 os
// candidatos à prefeitura (Capitão Gancho, Peter Pan e Wendy). Elabore um programa que permita ao
// usuário informar o número de votos de cada um dos candidatos, escrevendo em seguida o resultado
// da eleição. Sabe-se que, caso um dos candidatos tenha mais de 50% dos votos ele é eleito sem
// necessidade de segundo turno. Na “Terra do Nunca” não existem votos nulos ou brancos.

// 10. Existem números de 4 dígitos (entre 1000 e 9999) que obedecem à seguinte característica: se
// dividirmos o número em dois números de dois dígitos, um composto pela dezena e pela unidade, e
// outro pelo milhar e pela centena, se somarmos estes dois novos números gerando um terceiro, o
// quadrado deste terceiro número é exatamente o número original de quatro dígitos.
// Por exemplo: 2025 -> dividindo: 20 e 25 -> somando temos 45 -> 452 = 2025.
// Escreva um programa para ler um número e verificar se ele obedece a esta característica.

void louco(int num){
    char n[5];
    char n1[3], n2[3];
    int num1, num2, num3;
    sprintf(n, "%d", num);
    strncpy(n1, n, 2);
    n1[2] = '\0';
    strcpy(n2, n + 2);
    num1 = atoi(n1);
    num2 = atoi(n2);
    num3 = (num2 + num1) * (num2 + num1);
    if (num3 == num){
        printf("sim");
    }
    else{
        printf("nao");
    }
}

// 11. Uma loja de bicicletas paga a cada vendedor 2 salários mínimos mensais, mais uma comissão de 5%
// sobre as vendas das bicicletas, dividida igualmente entre eles. Escreva um programa que leia o
// número de empregados da loja, o valor do salário mínimo, o valor das vendas do mês e que calcule e
// escreva: o salário total de cada empregado.

// 12. O presidente de um país sul-americano quer investir em saúde, educação, habitação, segurança e
// previdência, que são as cinco metas de seu governo. Assim, o presidente decide criar mais um
// imposto, o ISSS (Imposto Sobre Seu Saldo), que é calculado sobre o saldo médio da conta-
// corrente, segundo a tabela abaixo:
// • Saldo  100: isento
// • 100  Saldo  1000: imposto devido é 1% sobre o saldo
// • 1000  Saldo  10000: imposto devido é de 2% sobre o saldo
// • 10000  Saldo  100000: imposto devido é de 3% sobre o saldo
// • Saldo  100000: imposto devido é de 5% sobre o saldo
// Faça um programa que permita ao usuário informar seu saldo bancário e que escreva o
// ISSS devido.

// 13. Considere as viagens que são realizadas entre as cidades de Metrópolis e Gotham City. Sabendo
// que todas as viagens entre estas cidades são feitas sempre dentro de um mesmo dia, elabore um
// programa que permita que um usuário informe o momento exato (hora, minuto, segundo) da sua
// partida e da sua chegada, e que calcule e escreva o tempo total da viagem (também em horas,
// minutos e segundos).

// 14. O síndico do condomínio Praias Oceânicas, que possui 4 blocos, instituiu uma nova forma de
// cobrança. Os condôminos dos blocos Itaipu e Itacoatiara pagam 10% a mais que os moradores dos
// blocos Camboinhas e Piratininga. Os moradores da cobertura pagam uma taxa extra fixa relativa a
// 1% do total do condomínio. Supondo que cada bloco possui 20 apartamentos simples e 4 coberturas,
// faça um programa que leia a taxa condominial básica e que informe o total arrecadado pelo síndico
// no mês, especificando também os valores diferenciados de cada condomínio.

int main(){
    int a;
    scanf("%d", &a);
    // triangulo(a, b, c);
    //opera(a, b);
    //categoria(a);
    louco(a);
}