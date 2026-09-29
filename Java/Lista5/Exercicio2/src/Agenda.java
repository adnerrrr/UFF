import java.util.ArrayList;
import java.util.List;

public class Agenda {
    public List<Contato> contatos = new ArrayList<>();

    public void adicionarContato(Contato novoContato) {
        contatos.add(novoContato);
        System.out.println("Contato " + novoContato.nome + " adicionado com sucesso.");
    }

    public void listarContatos() {
        System.out.println("\n--- Lista de Contatos ---");
        if (contatos.isEmpty()) {
            System.out.println("A agenda está vazia.");
        } else {
            for (Contato c : contatos) {
                System.out.println("Nome: " + c.nome + " | Telefone: " + c.numero);
            }
        }
    }
}