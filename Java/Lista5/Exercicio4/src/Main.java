public class Main {
    public static void main(String[] args) {
        // Criando uma conta com R$ 100,00 de saldo inicial
        Conta minhaConta = new Conta(100.0);

        // Testando as operações
        minhaConta.depositar(50.0);
        System.out.println("Saldo atual: R$ " + minhaConta.obterSaldo());

        // Tentando um saque válido
        minhaConta.sacar(40.0);
        System.out.println("Saldo após saque: R$ " + minhaConta.obterSaldo());

        // Tentando um saque inválido por falta de saldo para a taxa
        minhaConta.sacar(108.0);
    }
}