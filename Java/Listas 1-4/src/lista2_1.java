import java.util.Scanner;

public class lista2_1 {
    public static void main(String[] args){
//         Exercício 1: Leia duas variáveis inteiras e imprima a soma, subtração, multiplicação e
//         divisão entre elas.
        Scanner kb = new Scanner(System.in);
        int num1, num2;
        System.out.println("Digite um numero: ");
        num1 = kb.nextInt();
        System.out.println("Digite mais um numero: ");
        num2 = kb.nextInt();
        System.out.printf("Soma = %d \nDiferenca = %d \nProduto = %d\nDivisao = %d", num1+num2, num1-num2, num1*num2, num1/num2);
        kb.close();
    }
}
