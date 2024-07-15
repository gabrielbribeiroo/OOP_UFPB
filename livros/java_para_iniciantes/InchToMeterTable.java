package livros.java_para_iniciantes;

public class InchToMeterTable {
    public static void main(String[] args) {
        double inches, meters;
        int counter;

        counter = 0;
        for (inches=1; inches<=144; inches++) {
            meters = inches / 39.37; // Conversão para metros
            System.out.println(inches + " inches is " + meters + " meters.");
            counter++;

            if (counter == 12) {
                System.out.println(); // Pula uma linha a cada 12
                counter = 0; // Zera o contador de linhas
            }

        }
    }
}
