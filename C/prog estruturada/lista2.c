#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Faça um programa que apresente o peso total que será carregado por um caminhão. Sabe-se que
// este caminhão carrega 25 caixas. O peso de cada uma das caixas será informado pelo usuário.

void peso(){
    int s, peso;
    s = 0;
    for (int i = 0; i < 25; i++){
        scanf("%d", &peso);
        s += peso;
    }
    printf("%d", s);
}

// 2. Faça um programa que leia a quantidade e o preço de 50 produtos que foram comprados por uma
// empresa. Ao final deve ser escrito o total gasto pela empresa.

void gastos(){
    int quantia, preco, gasto = 0;
    for (int i = 0; i < 25; i++){
        printf("\nQuantia: ");
        scanf("%d", &quantia);
        printf("\nPreco: ");
        scanf("%d", &preco);
        gasto += quantia*preco;
    }
}

// 3. Faça um programa que leia 2 números inteiros positivos, A e B, e que calcule a soma de todos os
// números compreendidos entre eles. Os valores A e B não devem ser considerados no somatório.
// Caso A seja maior do que B deve ser enviada uma mensagem para o usuário informando que a
// soma não será realizada.

void soma(int a, int b){
    int s = 0;
    if (a >= b){
        printf("nao");
    }
    else{
        for (int i = a + 1; i < b; i++){
            s += i;
        }
        printf("%d", s);
    }
}

// 4. Faça um programa que leia 2 números inteiros positivos, A e B, e que calcule a soma de todos os
// números múltiplos de 4 compreendidos entre eles. Os valores A e B não devem ser considerados
// no somatório. Caso A seja maior do que B deve ser enviada uma mensagem para o usuário
// informando que a soma não será realizada.

void soma4(int a, int b){
    int s = 0;
    if (a >= b){
        printf("nao");
    }
    else{
        for (int i = a + 1; i < b; i++){
            if (i % 4 == 0)
                s += i;
        }
        printf("%d", s);
    }
}

// 5. Faça um programa que calcule a área total de uma casa (sala, cozinha, quartos, banheiros, etc).
// Considere que todos os cômodos são retangulares. O usuário deve entrar com a largura e o
// comprimento de cada cômodo da casa. O final da leitura será detectado quando for digitado um
// número negativo.

// 6. Faça um programa que apresente a tabuada de um número N, que será informado pelo usuário. O
// programa deve garantir que o valor digitado para N esteja entre 0 e 9.

// 7. Em um cinema, cada espectador respondeu a uma pesquisa, que perguntava a sua idade e a sua
// opinião em relação a um filme (O – Ótimo; B – Bom; R – Regular; P – Péssimo). Faça um programa
// que informe a média de idade das pessoas que responderam o questionário e a porcentagem dada
// para cada uma das respostas. O programa deve terminar quando o usuário digitar uma idade
// negativa.

// 8. Faça um programa que calcule o valor total que um edifício garagem arrecadou em um dia de
// operação, no qual 200 carros utilizaram o estacionamento. O algoritmo deve ler o horário de
// entrada (hora e minuto) assim como o de saída. Sabe-se que o valor mínimo cobrado é de 4 reais
// por um período 2 horas. A partir daí, cobra-se 1 real por hora adicional.

// 9. Faça um programa que leia um número K e escreva os termos da série de Fibonacci menores ou
// iguais a K. Faça a validação para que o valor de K seja maior do que 0.

// 10. A prefeitura de uma cidade resolveu fazer uma pesquisa entre os seus trabalhadores. Para isso
// ela coletou alguns dados como idade, sexo (M ou F) e salário. Faça um programa que leia estes
// dados e que escreva ao final:
// • a média salarial dos homens
// • a média salarial das mulheres
// • o maior salário encontrado entre as pessoas abaixo de 30 anos.
// Obs: O final da leitura de dados é marcado por uma idade negativa.

// 11. Faça um programa que escreva os N primeiros termos de uma PA. O primeiro termo, a1, e a
// razão da PA devem ser lidos.

// 12. Faça um programa que leia uma quantidade não determinada de números inteiros. O programa
// deve calcular e escrever a quantidade de números pares e ímpares, a média aritmética dos
// números pares e a divisão do somatório dos números pares pelo somatório dos números ímpares.
// O número que encerrará a leitura será zero, que não deve ser considerado.

// 13. Faça um programa que leia os nomes e os preços dos produtos de uma loja e que escreva o nome
// do produto mais caro. Considere que o final da lista é marcado pelo produto ‘XXX’ e que não
// existem preços repetidos.

// 14. Faça um programa que leia um número inteiro positivo N e calcule o valor da expressão abaixo.
// Caso o usuário digite um valor menor ou igual a zero, o algoritmo deve escrever uma mensagem
// informando que a expressão não pode ser calculada.

// 15. Faça um programa que calcule o fatorial de um número N.

void fatorial(int n){
    int fato = 1;
    for (int i = n; i > 1; i--){
        fato *= i;
    }
    printf("%d", fato);
}

// 16. Faça um programa que calcule o valor de E segundo a expressão abaixo:
// E = 2'1 + 2'2 + 2'3 + ... + 2'N-1 + 2'N

void eita(int n){
    int e = 0;
    int aux = 1;
    for (int j = n; j >= 1; j--){
        for (int i = j; i >= 1; i--){
            aux *= 2;
        }
        e += aux;
        aux = 1;
    }
    printf("%d", e);
}

// 17. Faça um programa que apure os votos de uma eleição presidencial onde concorreram três
// candidatos. Os votos podem ser 1, 2, 3 e 4 e devem ser contados de acordo com a tabela
// abaixo:
// 1 João da Silva
// 2 José Ramalho
// 3 Maria de Mattos
// 4 Voto em Branco
// Outros Voto Nulo
// Calcule e escreva o total de votos de cada candidato, o total de votos brancos, o total de
// votos nulos e o nome do candidato que recebeu mais votos.

int main(){
    // peso();
    int a;
    scanf("%d", &a);
    eita(a);
}