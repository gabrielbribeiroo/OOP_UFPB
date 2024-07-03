package condicionais;

import java.util.Scanner;

class Operacoes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading input at the terminal
        String input1 = scanner.nextLine();
        String op = scanner.nextLine();
        String input2 = scanner.nextLine();

        // Changing the input to integer and putting them into the x and y variables
        int x = Integer.parseInt(input1);
        int y = Integer.parseInt(input2);

        // Calculating the four basic operations
        if (op.equals("+")) {
            int sum = (int)(x + y);
            System.out.println(x + " " + op + " " + y + " = " + sum);
        }
        else if (op.equals("-")) {
            int sub = (int)(x - y);
            System.out.println(x + " " + op + " " + y + " = " + sub);
        }
        else if (op.equals("*")) {
            int pro = (int)(x * y);
            System.out.println(x + " " + op + " " + y + " = " + pro);
        }
        else if (op.equals("/")) {
            int quo = (int)(x / y);
            System.out.println(x + " " + op + " " + y + " = " + quo);
        }
        else {
            System.out.println("ERROR! Try again.");
        }

        scanner.close(); // Close the scanner to prevent resource leak
    }
    
}
