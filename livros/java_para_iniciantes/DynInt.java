/*
Demonstração da inicialização dinâmica.
*/

package livros.java_para_iniciantes;

public class DynInt {
    public static void main(String[] args) {
        double radius = 4, height = 5;
        double volume = 3.1416 * radius * radius * height; // Inicialização de volume dinamicamente no tempo de execução
        System.out.println("Volume is " + volume);
    }
}
