public class Main {
    public static void main(String[] args) {
        // Instanciando um aluno com suas notas (T1, P1, T2, P2)
        Materia aluno1 = new Materia(7.0, 5.0, 8.0, 6.0);
        Materia aluno2 = new Materia(3.0, 4.0, 5.0, 3.0);
        Materia aluno3 = new Materia(2.0, 3.0, 1.0, 2.0);

        // Exibindo os resultados do aluno 1
        System.out.println("--- Aluno 1 ---");
        System.out.println("Média: " + aluno1.calcularMedia());
        System.out.println("Status: " + aluno1.verificarStatus());

        // Exibindo os resultados do aluno 2
        System.out.println("\n--- Aluno 2 ---");
        System.out.println("Média: " + aluno2.calcularMedia());
        System.out.println("Status: " + aluno2.verificarStatus());

        // Exibindo os resultados do aluno 3
        System.out.println("\n--- Aluno 3 ---");
        System.out.println("Média: " + aluno3.calcularMedia());
        System.out.println("Status: " + aluno3.verificarStatus());
    }
}