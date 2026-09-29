import java.util.Scanner;

public class lista3_2 {
    // Exercício 2. Considere os programas a seguir, que leem um código repetidamente e imprimem o
    // código lido até que o código lido seja igual a -1. O código -1 não deve ser impresso.
    // a. Qual das duas soluções é a correta? RESPOSTA: o codigo 1 é o correto
    // b. Como a solução incorreta poderia ser corrigida?
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        int codigo;
        do {
            System.out.println("Digite o codigo: ");
            codigo = kb.nextInt();
            System.out.println("Codigo: " + codigo);
            if (codigo == -1) break;
        } while (codigo != -1);
        kb.close();
    }
}
