public class Livro {
    public String titulo;
    public String autor;
    public boolean disponivel; // Controla o estado do livro

    public Livro(String titulo, String autor) {
        this.titulo = titulo;
        this.autor = autor;
        this.disponivel = true; // Todo livro recém cadastrado está disponível
    }
}