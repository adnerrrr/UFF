public class Main {
    public static void main(String[] args) {
        Agenda minhaAgenda = new Agenda();

        Contato c1 = new Contato("Ana Silva", "99999-1111");
        Contato c2 = new Contato("Carlos Souza", "98888-2222");

        minhaAgenda.adicionarContato(c1);
        minhaAgenda.adicionarContato(c2);

        minhaAgenda.listarContatos();
    }
}