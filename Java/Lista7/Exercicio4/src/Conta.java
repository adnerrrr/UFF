public abstract class Conta {
    protected int numeroConta;
    protected float saldo;
    public Conta(int numeroConta, float saldo){
        this.numeroConta = numeroConta;
        this.saldo = saldo;
    }
    public void depositarDinheiro(float quantia){
        this.saldo += quantia;
    }
    public void sacarDinheiro(float quantia){
        if (quantia > this.saldo) {
            System.out.println("nao pode");
            return;
        }
        this.saldo -= quantia;
    }
    public void checarSaldo(){
        System.out.printf("%.2f\n", this.saldo);
    }
}
