import java.util.Scanner;

public class lista2_5 {
    // Exercício 5: Faça um programa que leia três coordenadas num espaço 2D e indique se
    // formam um triângulo, juntamente com o seu tipo (equilátero, isósceles e escaleno)
    // ○ Equilátero: todos os lados iguais
    // ○ Isósceles: dois lados iguais
    // ○ Escaleno: todos os lados diferentes
    public static void main(String [] args){
        Scanner kb = new Scanner(System.in);
        int a1, a2, b1, b2, c1, c2;
        double ab, cb, ac;
        boolean tri = false;
        System.out.println("Digite as coordenadas de A");
        System.out.print("X: ");
        a1 = kb.nextInt();
        System.out.print("Y: ");
        a2 = kb.nextInt();
        
        System.out.println("Digite as coordenadas de B");
        System.out.print("X: ");
        b1 = kb.nextInt();
        System.out.print("Y: ");
        b2 = kb.nextInt();
        
        System.out.println("Digite as coordenadas de C");
        System.out.print("X: ");
        c1 = kb.nextInt();
        System.out.print("Y: ");
        c2 = kb.nextInt();
        int ab1 = b1 - a1, ab2 = b2 - a2, ac1 = c1 - a1, ac2 = c2 - a2, cb1 = b1 - c1, cb2 = b2 - c2;
        ab = Math.sqrt(ab1*ab1 + ab2*ab2);
        ac = Math.sqrt(ac1*ac1 + ac2*ac2);
        cb = Math.sqrt(cb1*cb1 + cb2*cb2);
        kb.close();
        if (ab < cb + ac && cb < ac + ab && ac < cb + ac)
            tri = true;
        if (tri){
            if (ab == ac  && ab == cb)
                System.out.println("Equilatero");
            else if (ab == ac || ac == cb || cb == ab)
                System.out.println("Isosceles");
            else
                System.out.println("Escaleno");
        }
        else
            System.out.println("Nao e um triangulo");
    }
}