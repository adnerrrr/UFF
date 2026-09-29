import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Inverte {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);

        System.out.println("Digite uma frase:");
        String frase = kb.nextLine();

        String[] vetPalavras = frase.split(" "); // divide as palavras da frase num vetor

        // converte o vetor estatico pra uma lista
        List<String> listaPalavras = new ArrayList<>();
        for (String palavra : vetPalavras) {
            listaPalavras.add(palavra);
        }
        // ou pode converter com apenas essa funcao:
        // List<String> listaPalavras = Arrays.asList(vetPalavras); (mas ai tem que
        // importar java.util.arrays)

        Collections.reverse(listaPalavras); // usa Colections para inverter a ordem da lista

        // junta a lista em uma unica string unindo por com " " entre os itens
        String fraseInvertida = String.join(" ", listaPalavras);

        System.out.println("Frase invertida: " + fraseInvertida);
        kb.close();
    }
}