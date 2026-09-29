public class ContaEspecial extends Conta{
    protected float limite;
    public ContaEspecial(int numeroConta, float saldo, float limite){
        super(numeroConta, saldo);
        this.limite = limite;
    }
    @Override
    public void sacarDinheiro(float quantia){
        if (quantia > this.saldo + this.limite) return;
        this.saldo -= quantia;
    }
}
