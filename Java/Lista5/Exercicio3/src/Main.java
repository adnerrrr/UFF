public class Main {
    public static void main(String[] args) {
        // Instanciando as entidades
        Pessoa leitor = new Pessoa("João");
        Pessoa leitor2 = new Pessoa("Maria");

        Livro livro1 = new Livro("O Senhor dos Anéis", "J.R.R. Tolkien");

        // Realizando a transação
        Emprestimo transacao = new Emprestimo();
        transacao.realizarEmprestimo(leitor, livro1);

        // Tentando emprestar o mesmo livro (deve falhar)
        Emprestimo transacaoFalha = new Emprestimo();
        transacaoFalha.realizarEmprestimo(leitor2, livro1);

        // Devolvendo o livro
        transacao.devolverLivro();
    }
}