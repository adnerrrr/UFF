public class Main {
    public static void main(String[] args) {
        // Criando uma data válida em ano bissexto
        Data d1 = new Data(29, 2, 2024);
        System.out.print("Data 1: ");
        d1.imprime();
        System.out.println("É válida? " + d1.dataValida());
        System.out.println("É ano bissexto? " + d1.anoBissexto());

        System.out.println("--------------------");

        // Criando uma data inválida
        Data d2 = new Data(29, 2, 2023);
        System.out.print("Data 2: ");
        d2.imprime("-");
        System.out.println("É válida? " + d2.dataValida());
        System.out.println("É ano bissexto? " + d2.anoBissexto());
    }
}