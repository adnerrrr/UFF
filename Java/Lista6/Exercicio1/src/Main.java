import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Calculadora calc = new Calculadora();
        int opcao = 0;

        // Loop principal do programa
        do {
            System.out.println("\nEstado da memória: " + calc.getMemoria());
            System.out.println("Opções:");
            System.out.println("(1) Somar");
            System.out.println("(2) Subtrair");
            System.out.println("(3) Multiplicar");
            System.out.println("(4) Dividir");
            System.out.println("(5) Limpar memória");
            System.out.println("(6) Sair do programa");
            System.out.print("Qual opção você deseja? ");

            opcao = scanner.nextInt();
            double valor;

            // Estrutura de decisão para chamar os métodos
            switch (opcao) {
                case 1:
                    System.out.print("Digite o valor para somar: ");
                    valor = scanner.nextDouble();
                    calc.somar(valor);
                    break;
                case 2:
                    System.out.print("Digite o valor para subtrair: ");
                    valor = scanner.nextDouble();
                    calc.subtrair(valor);
                    break;
                case 3:
                    System.out.print("Digite o valor para multiplicar: ");
                    valor = scanner.nextDouble();
                    calc.multiplicar(valor);
                    break;
                case 4:
                    System.out.print("Digite o valor para dividir: ");
                    valor = scanner.nextDouble();
                    calc.dividir(valor);
                    break;
                case 5:
                    calc.limparMemoria();
                    System.out.println("Memória limpa!");
                    break;
                case 6:
                    System.out.println("Saindo do programa...");
                    break;
                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        } while (opcao != 6);

        scanner.close();
    }
}