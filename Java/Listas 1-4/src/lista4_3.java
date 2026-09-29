import java.util.Scanner;

public class lista4_3 {
    // 3. Crie um programa para ler um número n e um vetor v com n números inteiros. Depois,
    // ler mais um número k e um número p. Em seguida, inserir o número k na posição p do
    // vetor, deslocando os números da posição p em diante para frente uma posição (o
    // último número será perdido) e imprimir o vetor resultante. Caso p seja inválido
    // apresente a mensagem "Posição inválida".
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        System.out.println("Digite o tamanho do vetor: ");
        int tam = kb.nextInt();
        if (tam == 0){
            System.out.println("Vetor nulo");
            System.exit(1);
        }
        int vet[] = new int[tam];
        for (int i = 0; i<tam; i++){
            System.out.printf("Digite o numero na posicao %d: ", (i+1));
            vet[i] = kb.nextInt();
        }
        System.out.println("Digite o numero novo: ");
        int num = kb.nextInt();
        System.out.println("Digite a posicao do vetor: ");
        int p = kb.nextInt();
        p -= 1;
        if (p > tam)
            System.out.print("Posicao invalida");
        else{
            for (int j = tam-1; j>p-1; j--){
                vet[j] = vet[j-1];
            }
            vet[p-1] = num;
            for (int l = 0; l<tam; l++)
                System.out.printf("%d ", vet[l]);
        }
        kb.close();
    }
}
