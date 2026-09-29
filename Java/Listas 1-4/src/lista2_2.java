import java.util.Scanner;

public class lista2_2 {
    public static void main(String[] args){
//      Exercício 2: Altere o tipo das duas variáveis do exercício 1 para ponto flutuante.
        Scanner kb = new Scanner(System.in);
        int num1, num2;
        System.out.println("Digite um numero: ");
        num1 = kb.nextInt();
        System.out.println("Digite mais um numero: ");
        num2 = kb.nextInt();
        System.out.printf("Soma = %d \nDiferenca = %d \nProduto = %d\nDivisao = %d", num1+num2, num1-num2, num1*num2, num1/num2);
        kb.close();
        float num1conv, num2conv;
        num1conv = (float)num1;
        num2conv = (float)num2;
        System.out.println(num1conv + " " + num2conv);
    }
}
