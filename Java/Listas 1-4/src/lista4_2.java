import java.util.Scanner;

public class lista4_2 {
    // 2. Crie um programa para ler um número n e depois ler um vetor v com n números
    // inteiros. Ao final, ler mais um número k e informar e que posições do vetor v aparece o
    // número k. Caso k não exista no vetor v apresente a mensagem "Número não
    // encontrado".
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        int num = kb.nextInt();
        int vet[] = new int[num];
        for (int i = 0; i<num; i++){
            System.out.printf("Digite o numero %d: ", (i+1));
            vet[i] = kb.nextInt();
        }
        System.out.println("Digite o valor de k que deseja procurar: ");
        int k = kb.nextInt();
        boolean found = false;
        for (int j = 0; j<num; j++){
            if (vet[j] == k){
                System.out.printf("%d ", (j+1));
                found = true;
            }
        }
        if (found == false)
            System.out.println("Numero nao encontrado");
        kb.close();
    }
}
