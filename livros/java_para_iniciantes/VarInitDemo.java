/*
Demonstração do tempo de vida de uma variável.
*/

package livros.java_para_iniciantes;

public class VarInitDemo {
    public static void main(String[] args) {
        int x;

        for (x=0; x<3; x++) {
            int y = -1; // y será inicializada sempre que entrar no bloco
            System.out.println("y is: " + y); // Sempre exibe -1
            y = 100;
            System.out.println("y is now: " + y);
        }    
    }
}
