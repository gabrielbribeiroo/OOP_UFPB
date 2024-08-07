/*
Demonstração dos operadores de curto-circuito.
*/

package livros.java_para_iniciantes;

public class SCops {
    public static void main(String[] args) {
        int n, d;

        n = 10;
        d = 2;

        if (d!=0 && (n%d) == 0) {
            System.out.println(d + " is a factor of " + n);
        }

        d = 0; // Configura d com zero

        // Já que d é igual a zero, o segundo operando não é avaliado
        // O operador de curto-circuito (&&) impede uma divisão por zero
        // Sem o operador de curto-circuito (&), dará erro de divisão por zero
        if (d!=0 && (n%d) == 0) {
            System.out.println(d + " is a factor of " + n); 
        }

        // As duas expressões são avaliadas, permitindo que ocorra uma divisão por zero
        if (d!=0 & (n%d) == 0) {
            System.out.println(d + " is a factor of " + n);
        }
    }    
}
