import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        Operacoes calc = new Operacoes();
        try {
            System.out.print("Digite o primeiro número (ou o número base para raiz): ");
            double num1 = kb.nextDouble(); // Pode gerar InputMismatchException

            System.out.print("Digite a operação (soma, subtracao, multiplicacao, divisao, raiz): ");
            String operacao = kb.next();

            double num2 = 0;
            // Se não for raiz, pede o segundo número
            if (!operacao.equalsIgnoreCase("raiz")) {
                System.out.print("Digite o segundo número: ");
                num2 = kb.nextDouble(); // Pode gerar InputMismatchException
            }

            // Tratando as exceções geradas explicitamente pelo método executar()
            double resultado = calc.executar(num1, num2, operacao);
            System.out.println("Resultado: " + resultado);
        } catch (InputMismatchException e) {
            System.out.println("Digite apenas numeros!");
        } catch (ArithmeticException e) {
            System.out.println("Erro matematico" + e.getMessage());
        } catch (IllegalArgumentException e) {
            System.out.println("Erro de argumento" + e.getMessage());
        } finally { // eh executado sempre, com ou sem erro
            kb.close();
        }
    }
}