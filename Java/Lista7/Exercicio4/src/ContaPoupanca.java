public class ContaPoupanca extends Conta{
    public ContaPoupanca(int numeroConta, float saldo){
        super(numeroConta, saldo);
    }

    public void renderDinheiro(float taxa){
        float rendimento = this.saldo * (taxa/100);
        this.depositarDinheiro(rendimento);
    }
}
