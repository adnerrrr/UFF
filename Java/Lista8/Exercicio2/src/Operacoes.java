public class Operacoes {
    // 'throws' na assinatura avisa quem for usar o método
    public double executar(double a, double b, String op) throws ArithmeticException, IllegalArgumentException {
        switch (op.toLowerCase()) {
            case "soma":
                return a + b;

            case "subtracao":
                return a - b;

            case "multiplicacao":
                return a * b;

            case "divisao":
                if (b == 0)
                    throw new ArithmeticException("Divisao por zero nao permitida!");
                return a / b;
            case "raiz":
                if (a < 0)
                    throw new IllegalArgumentException("Nao existe raiz real de numero negativo!");
                return Math.sqrt(a);
            default:
                throw new IllegalArgumentException("Operacao invalida!");
        }
    }
}