public class Conta {
    public double saldo;

    // Construtor que inicializa a conta com um saldo inicial
    public Conta(double saldoInicial) {
        this.saldo = saldoInicial;
    }

    // Método para colocar dinheiro na conta
    public void depositar(double valor) {
        this.saldo += valor;
        System.out.println("Depósito de R$ " + valor + " realizado.");
    }

    // Método para retirar dinheiro aplicando a taxa de R$ 1,50
    public void sacar(double valor) {
        double custoTotal = valor + 1.50;

        if (this.saldo >= custoTotal) {
            this.saldo -= custoTotal;
            System.out.println("Saque de R$ " + valor + " realizado (Taxa: R$ 1,50).");
        } else {
            System.out.println("Erro: Saldo insuficiente para sacar R$ " + valor + " com a taxa.");
        }
    }

    // Método para apenas consultar o valor atual
    public double obterSaldo() {
        return this.saldo;
    }
}