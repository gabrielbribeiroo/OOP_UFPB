/*
Demonstração da coerção.
*/

package livros.java_para_iniciantes;

public class CastDemo {
    public static void main(String[] args) {
        double x, y;
        byte b;
        int i;
        char ch;

        x = 10.0;
        y = 3.0;

        i = (int) (x / y); // Converte double em int
        System.out.println("Integer outcome of x / y: " + i);

        i = 100;
        b = (byte) i; // Não há perda de informações (Um byte pode conter o valor 100)
        System.out.println("Value of b: " + b);

        i = 257;
        b = (byte) i; // Há perda de informações (Um byte não pode conter o valor 257)
        System.out.println("Value of b: " + b);

        b = 88; // ASCII para x
        ch = (char) b; // Coerção entre tipos incompatíveis
        System.out.println("ch: " + ch);
    }
}
