public class MainSalario {
    public static void main(String[] args) {

        Funcionario f1 = new Funcionario("Ana", 800);
        Funcionario f2 = new Funcionario("Carlos", 1200);
        Funcionario f3 = new Funcionario("Bia", 2000);

        Estagiario e1 = new Estagiario("Pedro", 600);

        Vendedor v1 = new Vendedor("Lucia", 1500, 10); // bônus de 10%

        System.out.println("=== FUNCIONÁRIOS ===");
        imprimir(f1);
        imprimir(f2);
        imprimir(f3);

        System.out.println("\n=== ESTAGIÁRIO ===");
        imprimir(e1);

        System.out.println("\n=== VENDEDOR ===");
        imprimirVendedor(v1);
    }

    static void imprimir(Funcionario f) {
        System.out.printf("%-10s | Bruto: R$ %7.2f | Líquido: R$ %7.2f%n",
                f.nome, f.salarioBruto, f.salarioLiquido());
    }

    static void imprimirVendedor(Vendedor v) {
        float total = v.salarioBruto + v.bonus;
        System.out.printf("%-10s | Bruto: R$ %7.2f | Bônus: R$ %7.2f | Total Bruto: R$ %7.2f | Líquido: R$ %7.2f%n",
                v.nome, v.salarioBruto, v.bonus, total, v.salarioLiquido());
    }
}