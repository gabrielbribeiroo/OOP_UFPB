/*
Conversão de galões em litros.
*/

package livros.java_para_iniciantes;

public class GalToLit {
    public static void main(String[] args) {
        double gallons; // Contém o número de galões
        double liters; // Contém o número de litros
        
        gallons = 10;

        liters = gallons * 3.7854; // Conversão para litros

        System.out.println(gallons + " gallons is " + liters + " liters.");
    }
}
