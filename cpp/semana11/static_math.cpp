#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Math_utils {
public:
    static double square(double x) {
        return (x*x);
    }

    static double square_root(double x) {
        return std::sqrt(x);
    }
};

int main() {
    double n = 9;

    cout << "Quadrado de " << n << ": " << Math_utils::square(n) << endl;
    cout << "Raiz quadrada de " << n << ": " << Math_utils::square_root(n) << endl;

    return 0;
}