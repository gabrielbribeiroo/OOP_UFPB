/*
Variáveis de caracteres podem ser tratadas como inteiros.
*/

package livros.java_para_iniciantes;

public class CharAritDemo {
    public static void main(String[] args) {
        char ch;
        
        ch = 'X';
        System.out.println("ch contains " + ch);

        ch++; // ch pode ser incrementada
        System.out.println("ch now is " + ch);

        ch = 90; // ch pode receber valores inteiros
        System.out.println("ch is now " + ch);
    }
}
