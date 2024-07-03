class ManipularStrings {
    public static void main(String[] args) {
        String s1 = "Gabriel ";
        String s2 = "Ribeiro";
        String s3 = s1 + s2; // String concatenation
        System.out.println("Nome: " + s3);

        boolean b1 = s3.isEmpty(); // Check if it's empty
        boolean b2 = s3.equals("Gabriel Ribeiro"); // Compare strings
        System.out.println(b1 + " " + b2);
    }
}
