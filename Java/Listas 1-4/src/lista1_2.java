import java.util.Scanner;

// 2 - Crie um programa que converta uma temperatura fornecida em graus Celsius para
// Fahrenheit usando a fórmula:

// F=(C×1.8)+32

// Exemplo de entrada:
// Digite a temperatura em Celsius: 25
// Exemplo de saída:
// 25°C equivalem a 77°F

public class lista1_2{
    public static void main(String [] args){
        Scanner teclado = new Scanner(System.in);
        System.out.println("Digite a temperatura em Celsius: ");
        float Celsius = teclado.nextFloat();
        float Fahrenheit = (Celsius * 1.8f) + 32;
        System.out.println(Celsius + "°C equivalem a " + Fahrenheit + "°F");
        teclado.close();
    }
}