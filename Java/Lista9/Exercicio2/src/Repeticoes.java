import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Repeticoes {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);

        System.out.println("Digite uma frase:");
        String frase = kb.nextLine();

        // quebra a frase em palavras
        String[] vetPalavras = frase.split(" ");

        // cria o HashSet (sem repeticoes)
        Set<String> setPalavras = new HashSet<>();

        // preenche
        for (String palavra : vetPalavras)
            setPalavras.add(palavra);

        System.out.println("Palavras nao repetidas: " + setPalavras.size());
        kb.close();
    }
}