import java.util.Scanner;

public class lista2_7 {
    // Exercício 7: Leia um número inteiro n e mais dois números (maior ou menor) que formam
    // um intervalo. Ao final, imprima uma mensagem informando se n está antes, dentro ou
    // depois do intervalo.
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        System.out.print("Digite um numero: ");
        int num = kb.nextInt();
        kb.nextLine();
        System.out.print("Digite o inicio do intervalo: ");
        int start = kb.nextInt();
        kb.nextLine();
        System.out.print("Digite o fim do intervalo: ");
        int end = kb.nextInt();
        kb.nextLine();
        if (num < start){
            System.out.println("O numero esta antes do intervalo");
        }
        else if (num > end){
            System.out.println("O numero esta depois do intervalo");
        }
        else{
            System.out.println("O numero esta dentro do intervalo");
        }
        kb.close();
    }
}
