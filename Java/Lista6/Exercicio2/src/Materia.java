public class Materia {
    // Encapsulamento: atributos privados
    private double trabalho1;
    private double prova1;
    private double trabalho2;
    private double prova2;

    public Materia(double t1, double p1, double t2, double p2) {
        this.trabalho1 = t1;
        this.prova1 = p1;
        this.trabalho2 = t2;
        this.prova2 = p2;
    }

    // Subprogramação: método responsável apenas pelo cálculo matemático
    public double calcularMedia() {
        return (this.trabalho1 + this.prova1 + this.trabalho2 + this.prova2) / 4.0;
    }

    // Subprogramação: método responsável apenas pela regra de negócio (status)
    public String verificarStatus() {
        double media = calcularMedia();

        if (media >= 6.0) {
            return "Aprovado";
        } else if (media >= 4.0) {
            return "Verificação Suplementar";
        } else {
            return "Reprovado";
        }
    }
}