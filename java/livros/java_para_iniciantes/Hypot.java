/*
Cálculo do comprimento da hipotenusa, a partir dos comprimentos dos dois lados opostos, pelo Teorema de Pitágoras.
*/

package livros.java_para_iniciantes;

public class Hypot {
    public static void main(String[] args) {
        double x, y, z;

        x = 3;
        y = 4;

        z = Math.sqrt(x*x + y*y); // Chamada do método sqrt da classe Math

        System.out.println("Hypotenuse is " + z);
    }    
}