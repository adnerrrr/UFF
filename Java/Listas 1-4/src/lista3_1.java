public class lista3_1 {
    //Exercício 1. Construa a tabela de multiplicação de números de 1 a 10
    public static void main(String [] args){
        for (int i = 1; i<=10; i++){
            for (int j = 1; j<=10; j++)
                System.out.printf("%d x %d = %d\n", i, j, i*j);
        }
    }
}
