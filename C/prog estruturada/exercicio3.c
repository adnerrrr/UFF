#include <stdio.h>
int main(void) {
    int n, x, tot, e;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    tot = 1;
    e = 1;
    for (int i = 1; i <= n; i++) {
        tot *= x;
        if (i % 2 == 0) {
            e += tot;
        }
        else {
            e -= tot;
        }
    }
    printf("O valor de E: %d", e);
}
