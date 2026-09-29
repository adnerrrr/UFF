#include <stdio.h>
int main(void){
    int n, soma;
    printf("Digite um numero: ");
    scanf("%d", &n);
    soma = n;
    for (int i = 1; i <= n/2; i++){
        if (n % i == 0) {
            printf("%d - ", i);
            soma += i;
        }
    }
    printf("%d \n", n);
    printf("A soma dos divisores e %d", soma);
}
