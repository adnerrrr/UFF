import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Usa método para isolar a leitura de dados
        int segundosDigitados = lerSegundosDoUsuario();

        // Instancia o objeto com o valor lido
        Conversor conversor = new Conversor(segundosDigitados);

        // Usa método para isolar a escrita (impressão) de dados
        exibirResultado(conversor);
    }

    // Método estático auxiliar para ler dados (Subprogramação)
    private static int lerSegundosDoUsuario() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite o tempo em segundos: ");
        int segundos = scanner.nextInt();
        scanner.close();
        return segundos;
    }

    // Método estático auxiliar para formatar a saída (Subprogramação)
    private static void exibirResultado(Conversor c) {
        int horas = c.obterHoras();
        int minutos = c.obterMinutos();
        int segundos = c.obterSegundosRestantes();

        System.out.println("\nTempo convertido:");
        System.out.println(horas + " hora(s), " + minutos + " minuto(s) e " + segundos + " segundo(s).");
    }
}