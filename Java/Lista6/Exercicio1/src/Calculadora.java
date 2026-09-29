public class Calculadora {
    // Encapsulamento: o atributo é privado, protegido contra alterações diretas
    private double memoria;

    public Calculadora() {
        this.memoria = 0.0;
    }

    // Subprogramação: métodos específicos para cada operação
    public void somar(double valor) {
        this.memoria += valor;
    }

    public void subtrair(double valor) {
        this.memoria -= valor;
    }

    public void multiplicar(double valor) {
        this.memoria *= valor;
    }

    public void dividir(double valor) {
        if (valor != 0) {
            this.memoria /= valor;
        } else {
            System.out.println("Erro: Divisão por zero não é permitida.");
        }
    }

    public void limparMemoria() {
        this.memoria = 0.0;
    }

    // Método para permitir a leitura controlada da memória
    public double getMemoria() {
        return this.memoria;
    }
}