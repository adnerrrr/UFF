#include <stdio.h>
char menu() {
    char op;
    printf("SELECIONE UMA OPERACAO: \n'+' ADICAO \n'-'SUBTRACAO \n'*'MULTIPLICACAO\n'/'DIVISAO\n'$'POTENCIA\n'!'ENCERRAR PROGRAMA\nESCOLHA: ");
    scanf(" %c", &op);
    return op;
}
int opvalido(char op) {
    if (op != '+' || op != '-' || op != '*' || op != '/' || op != '&'){
        return 1;
    }
    else {
        return 0;
    }
}
// int potencia(int a, int b) {
//     int total;
//     total = a;
//     for (int i = 1; i < b; i++) {
//         total *= a;
//     }
//     return total;
// }
int potencia(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else{
        return a * potencia(a, b - 1);
    }
}
void operacao(int a, int b, char op) {
    switch (op) {
        case '+':
            printf("%d \n", a + b);
            break;
        case '-':
            printf("%d \n", a - b);
            break;
        case '*':
            printf("%d \n", a * b);
            break;
        case '/':
            printf("%d \n", a / b);
            break;
        case '$':
            printf("%d \n", potencia(a, b));
            break;
    }
}

int main(void){
    char op = menu();
    int a, b;
    while (op != '!') {
        if (opvalido(op)) {
            printf("Digite o valor A: ");
            scanf("%d", &a);
            printf("Digite o valor de B: ");
            scanf("%d", &b);
            operacao(a, b, op);
        }
        else {
            printf("Operacao inexistente.");
        }
        op = menu();
    }
}