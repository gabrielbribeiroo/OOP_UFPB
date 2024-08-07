/*
Demonstração dos operadores relacionais e lógicos.
*/

package livros.java_para_iniciantes;

public class RelLogOps {
    public static void main(String[] args) {
        int i, j;
        boolean b1, b2;

        i = 10;
        j = 11;
        if (i < j) System.out.println("i < j");
        else if (i <= j) System.out.println("i <= j");
        else if (i != j) System.out.println("i != j");
        else if (i == j) System.out.println("this won't execute.");
        else if (i >= j) System.out.println("this won't execute.");
        else if (i > j) System.out.println("this won't execute.");

        b1 = true;
        b2 = false;
        if (b1 & b2) System.out.println("this won't execute.");
        else if (!(b1 & b2)) System.out.println("!(b1 & b2) is true.");
        else if (b1 | b2) System.out.println("b1 | b2 is true.");
        else if (b1 ^ b2) System.out.println("b1 ^ b2 is true.");
    }
}
