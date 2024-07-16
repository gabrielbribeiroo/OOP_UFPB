/*
Diferença entre int e double. 
*/

package livros.java_para_iniciantes;

public class Exemplo3 {
    public static void main(String[] args) {
        int var; // Variável do tipo inteiro
        double x; // Variável do tipo ponto flutuante de dupla precisão

        var = 10;
        x = 10.0;

        System.out.println("Original value for var: " + var);
        System.out.println("Original value for x: " + x);
        System.out.println();

        var = var / 4;
        x = x / 4;

        System.out.println("var after division: " + var);
        System.out.println("x after division: " + x);
    }
}
