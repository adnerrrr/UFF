public class Funcionario {
    public String nome;
    public float salarioBruto;

    public Funcionario(String nome, float salario){
        this.nome = nome;
        this.salarioBruto = salario;
    }

    protected float calculaIR(float salario){
        if (salario <= 900){
            return 0;
        }
        else if (salario <= 1500){
            return (salario * 0.15f);
        }
        else {
            return (salario * 0.2f);
        }
    }

    public float salarioLiquido(){
        return (salarioBruto - calculaIR(salarioBruto));
    }
}
