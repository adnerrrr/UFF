import java.util.Scanner;

// 3 - Crie um programa que peça um número ao usuário e diga se ele é par ou ímpar.
// Exemplo de entrada:
// Digite um número: 10
// Exemplo de saída:
// O número 10 é par.

public class lista1_3 {
    public static void main(String [] args){
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite um numero: ");
        int num = teclado.nextInt();
        if (num % 2 == 0) {
            System.out.println("O numero " + num + " e par");
        }
        else {
            System.out.println("O numero " + num + " e impar");
        }
        teclado.close();
    }
}
