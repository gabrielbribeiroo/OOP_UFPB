package condicionais;

import java.util.Scanner;

class Operacoes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading input at the terminal
        System.out.println("----------\nCALCULATOR\n----------");
        System.out.print("Operator: ");
        String op = scanner.nextLine(); // Reading operator

        // Calculating the four basic operations
        if (op.equals("+")) {
            // Reading the numbers
            System.out.print("Number 1: ");
            String num1 = scanner.nextLine();
            System.out.print("Number 2: ");
            String num2 = scanner.nextLine();
            // Changing the input to integer and putting them into the x and y variables
            int x = Integer.parseInt(num1);
            int y = Integer.parseInt(num2);
            int sum = (int)(x + y); // Calculation the sum of numbers
            System.out.println(x + " " + op + " " + y + " = " + sum); // Print the result
        }
        else if (op.equals("-")) {
            // Reading the numbers
            System.out.print("Number 1: ");
            String num1 = scanner.nextLine();
            System.out.print("Number 2: ");
            String num2 = scanner.nextLine();
            // Changing the input to integer and putting them into the x and y variables
            int x = Integer.parseInt(num1);
            int y = Integer.parseInt(num2);
            int sub = (int)(x - y); // Calculation the subtraction of numbers
            System.out.println(x + " " + op + " " + y + " = " + sub); // Print the result
        }
        else if (op.equals("*")) {
            // Reading the numbers
            System.out.print("Factor 1: ");
            String num1 = scanner.nextLine();
            System.out.print("Factor 2: ");
            String num2 = scanner.nextLine();
            // Changing the input to integer and putting them into the x and y variables
            int x = Integer.parseInt(num1);
            int y = Integer.parseInt(num2);
            int pro = (int)(x * y); // Calculation the multiplication of numbers
            System.out.println(x + " " + op + " " + y + " = " + pro); // Print the result
        }
        else if (op.equals("/")) {
            // Reading the numbers
            System.out.print("Dividing 1: ");
            String num1 = scanner.nextLine();
            System.out.print("Dividing 2: ");
            String num2 = scanner.nextLine();
            // Changing the input to integer and putting them into the x and y variables
            int x = Integer.parseInt(num1);
            int y = Integer.parseInt(num2);            
            int quo = (int)(x / y); // Calculation of the integer part of the division between numbers
            System.out.println(x + " " + op + " " + y + " = " + quo); // Print the result
        }
        else if (op.equals("%")) {
            // Reading the numbers
            System.out.print("Dividing 1: ");
            String num1 = scanner.nextLine();
            System.out.print("Dividing 2: ");
            String num2 = scanner.nextLine();
            // Changing the input to integer and putting them into the x and y variables
            int x = Integer.parseInt(num1);
            int y = Integer.parseInt(num2); 
            int res = (int)(x % y); // Calculation of the remainder of the integer division between numbers      
            System.out.println(x + " " + op + " " + y + " = " + res); // Print the result      
        }
        else {
            System.out.println("ERROR! Try again.");
        }

        scanner.close(); // Close the scanner to prevent resource leak
    }
}
