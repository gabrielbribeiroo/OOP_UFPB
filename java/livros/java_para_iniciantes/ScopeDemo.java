/*
Demonstração do espaço de bloco.
*/

package livros.java_para_iniciantes;

public class ScopeDemo {
    public static void main(String[] args) {
        int x; // Pode ser utilizada apenas dentro da main

        x = 10;
        if (x == 10) { // Início de novo escopo
            int y = 20; // Conhecida apenas nesse bloco
            // x e y são conhecidas nesse bloco
            System.out.println("x and y: " + x + " " + y);
            x = y * 2;
        }

        // y = 100; // ERRO! y não é conhecida aqui (fora do escopo da declaração)
        // x ainda é conhecida aqui
        System.out.println("x is " + x);
    }
}
