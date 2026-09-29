public class Primos extends Thread {
    private int ini, fim, contPrimos;

    public Primos(int ini, int fim) { // definir o lote de trabalho da thread
        this.ini = ini;
        this.fim = fim;
        this.contPrimos = 0;
    }

    private boolean ehPrimo(int numero) { // verificar se eh primo
        if (numero <= 1) {
            return false;
        }
        if (numero == 2) {
            return true;
        }
        if (numero % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= Math.sqrt(numero); i += 2) {
            if (numero % i == 0) {
                return false;
            }
        }
        return true;
    }

    @Override
    public void run() {
        for (int i = this.ini; i < this.fim; i++) {
            if (ehPrimo(i))
                this.contPrimos += 1;
        }
    }

    public int getContPrimos() {
        return this.contPrimos;
    }

}