public class Cliente extends Usuario{
    protected int dadoCadastral1;
    protected String dadoCadastral2;
    public Cliente(String nome, String senha){
        this.nome = nome;
        this.senha = senha;
        //adicionar dados extras
    }
}
