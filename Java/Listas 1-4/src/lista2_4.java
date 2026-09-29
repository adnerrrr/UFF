import java.util.Scanner;

public class lista2_4 {
    public static void main(String [] args){
//         Exercício 4: Faça um programa que leia a distância percorrida por um carro, o tempo gasto
//         e a quantidade de gasolina consumida. Em seguida, imprima a velocidade média (KM/h) e
//         o consumo de combustível (Km/l).
        Scanner kb = new Scanner(System.in);
        System.out.println("Digite a distancia percorrida: ");
        int dist = kb.nextInt();
        System.out.println("Digite o tempo gasto");
        int time = kb.nextInt();
        System.out.println("Digite a gasolina gasta: ");
        int gas = kb.nextInt();
        System.out.printf("%d km/h \n%d km/l", dist/time, dist/gas);
        kb.close();
    }
}
