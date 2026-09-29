public class Circulo {
    // Encapsulamento: atributos privados impedem o acesso direto externo
    private double x;
    private double y;
    private double raio;

    // Construtor para inicializar as coordenadas e o raio
    public Circulo(double x, double y, double raio) {
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    // Métodos de Acesso: Getters e Setters para o X
    public double getX() {
        return this.x;
    }

    public void setX(double x) {
        this.x = x;
    }

    // Métodos de Acesso: Getters e Setters para o Y
    public double getY() {
        return this.y;
    }

    public void setY(double y) {
        this.y = y;
    }

    // Métodos de Acesso: Getters e Setters para o Raio
    public double getRaio() {
        return this.raio;
    }

    public void setRaio(double raio) {
        if (raio > 0) {
            this.raio = raio;
        } else {
            System.out.println("Erro: O raio deve ser maior que zero.");
        }
    }

    // Método de cálculo equivalente à área do Retângulo
    public double calcularArea() {
        return Math.PI * Math.pow(this.raio, 2);
    }

    // Método de cálculo equivalente ao perímetro do Retângulo
    public double calcularPerimetro() {
        return 2 * Math.PI * this.raio;
    }
}