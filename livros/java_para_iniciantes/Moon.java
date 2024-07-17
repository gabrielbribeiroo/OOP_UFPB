/*
Calcula o peso na lua. 
*/

package livros.java_para_iniciantes;

public class Moon {
    public static void main(String[] args) {
        double earth_weight; // Peso na terra
        double moon_weight; // Peso na lua

        earth_weight = 165;
        moon_weight = earth_weight * 0.17;

        System.out.println(earth_weight + " earth-pounds is equivalent to " + moon_weight + " moon-pounds.");
    }
}
