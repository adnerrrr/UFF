import java.util.Scanner;

// 4 - Crie um programa para, a partir de um valor informado em centavos, indicar a menor
// quantidade de moedas que representa esse valor
// – Considere moedas de 1, 5, 10, 25 e 50 centavos, e 1 real
// – Exemplo: para o valor 290 centavos, a menor quantidade de moedas é 2 moedas
// de 1 real, 1 moeda de 50 centavos, 1 moeda de 25 centavos, 1 moeda de 10
// centavos e 1 moeda de 5 centavos

public class lista1_4 {
    public static void main(String [] args){
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite uma quantidade de centavos: ");
        int total = teclado.nextInt();
        int real = total / 100;
        System.out.println(real +" moedas de 1 real");
        int cent = total % 100;
        if (cent >= 50){
            cent -= 50;
            System.out.println("1 moeda de 50 centavos");
        }
        if (cent >= 25){
            cent -= 25;
            System.out.println("1 moeda de 25 centavos");
        }
        if (cent >= 20){
            cent -= 20;
            System.out.println("2 moeda de 10 centavos");
        }
        if (cent >= 10){
            cent -= 10;
            System.out.println("1 moeda de 10 centavos");
        }
        if (cent >= 5){
            cent -= 5;
            System.out.println("1 moeda de 5 centavos");
        }
        System.out.print(cent + " moedas de 1 centavo");
        teclado.close();
    }
}
