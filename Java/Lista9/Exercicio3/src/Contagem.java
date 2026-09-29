import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class Contagem {
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);

        System.out.println("Digite uma frase:");
        String frase = kb.nextLine();

        String[] vetPalavras = frase.split(" ");

        // cria o hashmap ligando cada palavra(chave) à quantidade de ocorrências dela
        Map<String, Integer> contagemMap = new HashMap<>();

        // percorre todas as palavras para ir interando quandtas vezes aparece
        for (String palavra : vetPalavras) {
            // logica simples de: se ja existe, soma 1 no valor, se nao, adiciona como 1
            if (contagemMap.containsKey(palavra)) {
                int qtd = contagemMap.get(palavra);
                contagemMap.put(palavra, qtd + 1);
            } else
                contagemMap.put(palavra, 1);
        }

        // printar o map
        for (String palavra : contagemMap.keySet())
            System.out.println(palavra + ": " + contagemMap.get(palavra));
        kb.close();
    }
}