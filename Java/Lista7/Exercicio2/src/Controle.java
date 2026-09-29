import java.util.ArrayList;
import java.util.Random;
import java.util.List;
public class Controle {
    public static void main(String [] args){
        Random geraNum = new Random();
        int nextAnimal;
        List<Animal> lista = new ArrayList<>();
        for (int i = 0; i<10; i++){
            nextAnimal = geraNum.nextInt(3);
            switch (nextAnimal) {
                case 0:
                    lista.add(new Cachorro());
                    break;
                case 1:
                    lista.add(new Gato());
                    break;
                case 2:
                    lista.add(new Homem());
                    break;
            }
        }
        for (Animal animal : lista){
            animal.fala();
        }
    }
}
