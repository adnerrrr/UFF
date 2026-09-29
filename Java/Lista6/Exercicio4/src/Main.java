import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Leitura dos dados solicitados no enunciado
        System.out.print("Digite a coordenada X do centro: ");
        double x = scanner.nextDouble();

        System.out.print("Digite a coordenada Y do centro: ");
        double y = scanner.nextDouble();

        System.out.print("Digite o valor do raio: ");
        double raio = scanner.nextDouble();

        // Instanciação do objeto Círculo com os dados lidos
        Circulo c = new Circulo(x, y, raio);

        // Exibição dos dados e cálculos através dos métodos
        System.out.println("\n--- Dados do Círculo Criado ---");
        System.out.println("Centro: (" + c.getX() + ", " + c.getY() + ")");
        System.out.println("Raio: " + c.getRaio());
        System.out.println("Área: " + c.calcularArea());
        System.out.println("Perímetro: " + c.calcularPerimetro());

        scanner.close();
    }
}