/*
Encontra os números primos de 2 a 100.
*/

package livros.java_para_iniciantes;

public class Prime {
    public static void main(String[] args) {
        int i, j;

        for (i=2; i<100; i++) {
            // Verifica se o número possui divisão exata
            for (j=2; j<=i/j; j++) {
                // Se tiver, não é primo
                if (i % j != 0) {
                    System.out.println(i + " is prime.");
                }
            }          
        }

    }
}
