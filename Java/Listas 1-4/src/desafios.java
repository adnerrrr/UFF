import java.util.Random;
import java.util.Scanner;

public class desafios {
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        Random rand = new Random();
        int num = rand.nextInt(1, 38);
        System.out.println(num);
        kb.nextLine();
        kb.close();
    }
}
