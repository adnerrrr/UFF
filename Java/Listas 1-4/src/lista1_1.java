import java.util.Scanner;

// 1 - Crie um programa que peça ao usuário para digitar seu nome e, em seguida, exiba uma
// mensagem personalizada com o nome informado.
// Exemplo de entrada:
// Digite seu nome: Rebeca
// Exemplo de entrada:
// Olá, Rebeca! Bem-vindo ao Java!

public class lista1_1{
    public static void main(String [] args){
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite seu nome: ");
        String nome = teclado.nextLine();
        System.out.println("Ola " + nome + " Bem vindo ao java!");
        teclado.close();
    }
}