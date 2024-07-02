import java.util.Scanner;

class HelloWorld {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); 
        String name = scanner.nextLine(); // Variable name of the string class receives input typed by the user
        System.out.println("Hello, " + name + "!");
        scanner.close(); // Close the scanner to prevent resource leak
    }
}