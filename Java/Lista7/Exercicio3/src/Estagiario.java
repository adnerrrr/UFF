public class Estagiario extends Funcionario{
    public Estagiario(String nome, float salario){
        super(nome, salario);
    }
    // nao pagam IR
    @Override
    public float salarioLiquido(){
        return salarioBruto;
    }
}
