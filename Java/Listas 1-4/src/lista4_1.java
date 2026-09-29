import java.util.Scanner;

public class lista4_1 {
    // 1. Crie um programa para ler inicialmente o número de alunos de uma turma. Em
    // seguida, leia as notas dos alunos dessa turma. Ao final, imprima a média da turma e as
    // notas acima da média.
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        System.out.print("Digite o numero de alunos da turma: ");
        int num = kb.nextInt();
        float [] turma = new float[num];
        float total = 0; 
        for (int i = 0; i<num; i++){
            System.out.printf("Digite a nota do aluno %d: ", (i+1));
            turma[i] = kb.nextFloat();
            total += turma[i];
        }
        float med = total / (float)num;
        System.out.printf("A media da turma eh: %.2f\n", med);
        for (float n : turma)
            if (n >= med) 
                System.out.printf("%.2f ", n);
        kb.close();
    }
}
