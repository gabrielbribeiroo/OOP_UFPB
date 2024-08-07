/*
Efeitos colaterais podem ser importantes.
*/
package livros.java_para_iniciantes;

public class SideEffects {
    public static void main(String[] args) {
        int i;
        
        i = 0;

        // i é incrementada, mesmo que a instrução seja falsa
        if (false & (++i < 100)) {
            System.out.println("this won't be displayed.");
        }
        System.out.println("if statement executed: " + i); // Exibe 1

        // i não é incrementada, porque o operador de curto-circuito ignora o incremento
        if (false && (++i < 100)) {
            System.out.println("this won't be displayed.");
        }
        System.out.println("if statement executed: " + i); // Continua exibindo 1


    }
}
