/*
Tentativa de declarar uma variável em um escopo interno com o mesmo nome de uma definida em um escopo externo, porém terá erro de compilação.
*/

package livros.java_para_iniciantes;

public class NestVar {
    public static void main(String[] args) {
        int count; 

        for (count=0; count<10; count++) {
            System.out.println("This is count: " + count);
            // int count; // Inválido! (Não é possível declarar a mesma variável duas vezes)
            for (count=0; count<2; count++) {
                System.out.println("This program is in error.");
            }
        }
    }
}
