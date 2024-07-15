package livros.java_para_iniciantes;

public class GalToLitTable {
    public static void main(String[] args) {
        double gallons, liters;
        int counter;

        counter = 0; // Contador de linhas inicializado com 0
        for (gallons=1; gallons<=100; gallons++) {
            liters = gallons * 3.7854; // Conversão para litros
            System.out.println(gallons + " gallons is " + liters + " liters.");
            counter++; // Incremento do contador a cada iteração
            
            if (counter == 10) {
                System.out.println(); // Pula uma linha a cada 10
                counter = 0; // Zera o contador de linhas
            }
        }

    }
}
