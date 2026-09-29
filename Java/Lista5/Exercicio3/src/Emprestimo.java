public class Emprestimo {
    public Pessoa pessoa;
    public Livro livro;
    public boolean ativo; // Define se o empréstimo ainda está correndo

    // Método que concretiza o empréstimo
    public void realizarEmprestimo(Pessoa p, Livro l) {
        if (l.disponivel) {
            this.pessoa = p;
            this.livro = l;
            this.ativo = true;
            l.disponivel = false; // Altera o estado do livro
            System.out.println("Empréstimo do livro '" + l.titulo + "' para " + p.nome + " realizado.");
        } else {
            System.out.println("O livro '" + l.titulo + "' não está disponível no momento.");
        }
    }

    // Método para devolver o livro
    public void devolverLivro() {
        if (this.ativo) {
            this.livro.disponivel = true; // Livro volta a ficar disponível
            this.ativo = false; // Empréstimo é encerrado
            System.out.println("Livro '" + this.livro.titulo + "' devolvido por " + this.pessoa.nome + ".");
        } else {
            System.out.println("Este empréstimo já foi encerrado.");
        }
    }
}