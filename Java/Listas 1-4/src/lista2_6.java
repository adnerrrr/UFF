import java.util.Scanner;

public class lista2_6 {
    // Exercício 6: Faça um programa que para cada produto informado (nome, preço e
    // quantidade), escreva o nome do produto comprado e o valor total a ser pago, considerando
    // que são oferecidos descontos pelo número de unidades compradas, segundo as opções
    // abaixo:
    // a. Até 10 unidades: valor total
    // b. de 11 a 20 unidades: 10% de desconto
    // c. de 21 a 50 unidades: 20% de desconto
    // d. acima de 50 unidades: 25% de desconto
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        String nome;
        System.out.println("Digite o nome do produto: ");
        nome = kb.nextLine();
        float valor;
        System.out.println("Digite o valor do produto: ");
        valor = kb.nextFloat();
        int quant;
        System.out.println("Digite a quantidade de produtos: ");
        quant = kb.nextInt();
        if (quant < 0)
            System.out.print("hilario");
        else if (quant <= 10)
            System.out.printf("%d %s por: %f", quant, nome, valor);
        else if (quant <= 20)
            System.out.printf("%d %s por: %f", quant, nome, valor * 0.9);
        else if (quant <= 50)
            System.out.printf("%d %s por: %f", quant, nome, valor * 0.8);
        else
            System.out.printf("%d %s por: %f", quant, nome, valor * 0.75);
        kb.close();
    }
}
