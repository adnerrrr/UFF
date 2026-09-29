import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String [] args){
        int num = 0;
        Somatorio sum = new Somatorio();
        Scanner kb = new Scanner(System.in);
        do{
            try{
                num = kb.nextInt();
                kb.nextLine();
                sum.adicionar(num);
            } catch(InputMismatchException e){
                System.out.println("Entrada invalida");
                kb.nextLine();
                num = kb.nextInt();
                sum.adicionar(num);
            }
        } while(num > 0);
        System.out.printf("A soma dos numeros e %d", sum.sum);
        kb.close();
    }
}
