/*
Promoção de um inesperado.
 */

package livros.java_para_iniciantes;

public class PromDemo {
    public static void main(String[] args) {
        byte b;
        int i;

        b = 10;
        i = b * b; // Não é necessária a coerção, porque o resultado já é elevado para int.

        b = 10;
        b = (byte) (b * b); // Coerção é necessária para atribuir um int a um byte. 

        System.out.println("i and b: " + i + " " + b);
    }
}
