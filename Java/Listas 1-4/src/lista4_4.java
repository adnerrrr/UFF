import java.util.Scanner;
import java.util.Arrays;

public class lista4_4 {
    // 4. Leia o nome e a idade de 10 pessoas e liste as pessoas
    // – Em ordem alfabética
    // – Em ordem crescente de idade
    public static void main(String [] args){
        int n = 10;
        Scanner kb = new Scanner(System.in);
        String nomes[] = new String[n];
        int idades[] = new int[n];
        for (int i = 0; i<n; i++){
            System.out.print("Digite o nome da pessoa: ");
            nomes[i] = kb.nextLine();
            System.out.print("Digite a idade da pessoa: ");
            idades[i] = kb.nextInt();
            kb.nextLine();
        }
        int auxNum;
        String auxNome;
        for (int a = 0; a<n; a++){
            for (int j = 0; j<n-a-1; j++){
                if (idades[j] > idades[j+1]){
                    auxNum = idades[j];
                    auxNome = nomes[j];
                    idades[j] = idades[j+1];
                    nomes[j] = nomes[j+1];
                    idades[j+1] = auxNum;
                    nomes[j+1] = auxNome;
                }
            }
        }
        System.out.println("\nOrdenado por idades: ");
        for (int b = 0; b<n; b++)
            System.out.printf("%s || ", nomes[b]);
        Arrays.sort(nomes);
        System.out.println("\nOrdenado por nome: ");
        for (int c = 0; c<n; c++)
            System.out.printf("%s || ", nomes[c]);
        kb.close();
    }
}
