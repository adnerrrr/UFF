import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        int n;
        System.out.println("Escreva o numero 'n':");
        while (true) {
            try {
                n = kb.nextInt();
                if (n < 0)
                    System.out.println("Coloque um numero positivo");
                else
                    break;
            } catch (InputMismatchException error) {
                System.out.println("Coloque um numero");
            }
        }
        int metade = n / 2; // divide a tarefa para cada thread

        Primos t1 = new Primos(0, metade); // aloca as threads com os lotes diferentes
        Primos t2 = new Primos(metade + 1, n);

        t1.start(); // inicializa a linha de execucao (paralela)
        t2.start();

        try {
            t1.join(); // a main aguarda as duas threads terminarem as execucoes
            t2.join();
        } catch (InterruptedException error) {
            System.out.println("Ocorreu algum erro ao esperar as threads");
        }
        int totalPrimos = t1.getContPrimos() + t2.getContPrimos(); // soma os resultados individuais de cada uma

        System.out.print("Thread 1: " + t1.getContPrimos() + "\nThread 2: " + t2.getContPrimos() + "\nTotal de primos: "
                + totalPrimos);
        kb.close();
    }
}