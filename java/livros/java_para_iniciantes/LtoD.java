/*
Demonstração da conversão automática de long para double.
*/

package livros.java_para_iniciantes;

class LtoD {
    public static void main(String[] args) {
        long l;
        double d;

        l = 100123285l;
        d = l; // Conversão automática de long para double
        System.out.println("L and D: " + l + " " + d);

        d = 100123285.0;
        // l = d; // Inválido (Não há conversão automática)
        System.out.println("L and D: " + l + " " + d);
    }
}