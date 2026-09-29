public class Vendedor extends Funcionario{
    public float bonus;

    public Vendedor(String nome, float salario, float bonus){
        super(nome, salario);
        this.bonus = bonus;
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

    protected float calculaBonus(float salario){
        return (salario * (bonus/100));
    }

    @Override
    public float salarioLiquido(){
        // (bruto + bonus) - IR
        salarioBruto = salarioBruto + calculaBonus(salarioBruto);
        return (salarioBruto - calculaIR(salarioBruto));
    }
}
