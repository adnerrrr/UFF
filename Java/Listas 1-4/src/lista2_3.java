import java.util.Scanner;

public class lista2_3 {
    public static void main(String [] args){
//         Exercício 3: Leia uma variável t com um tempo qualquer em segundos e imprima esse
//         valor em hora, minuto e segundo.
        Scanner kb = new Scanner(System.in);
        System.out.println("Digite um valor em segundos para ser convertido:");
        int sec = kb.nextInt();
        int min = 0, hora = 0;
        if (sec >= 60){
            min = sec/60;
            sec = sec%60;
        }
        if (min >= 60){
            hora = min/60;
            min = hora%60;
        }
        System.out.printf("%d h, %d min, %d seg\n", hora, min, sec);
        kb.close();
    }
}
