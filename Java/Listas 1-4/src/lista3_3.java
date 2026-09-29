import java.util.Scanner;

public class lista3_3 {
    // Exercício 3. Escreva um programa em Java que analise uma palavra ou frase digitada pelo usuário e:
    // ○ Exiba o número total de caracteres
    // ○ Exiba tudo em maiúsculo
    // ○ Exiba tudo em minúsculo
    // ○ Conte quantas vezes a letra A aparece
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        System.out.println("Digite uma palavra ou frase: ");
        String frase = kb.nextLine();
        int len = frase.length(), a = 0;
        for (int i = 0; i<len; i++){
            if (frase.charAt(i) == 'a' || frase.charAt(i) == 'A')
                a++;
        }
        System.out.println(frase.toUpperCase());
        System.out.println(frase.toLowerCase());
        System.out.printf("Total de A: %d || Total de letras: %d", a, len);
        kb.close();
    }
}
