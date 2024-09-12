#include <iostream>

using std::cout;
using std::endl;

class Ponto {
    double x;
    double y;
    static int contador;
public:
    Ponto(double xx, double yy): x(xx), y(yy) {
        contador++;
    }

    ~Ponto() {
        contador--;
    }

    static int get_contador() {
        return contador;
    }

    void print_info() {
        cout << "ponto(" << x << ", " << y << ")" << endl;
    }
};

int Ponto::contador = 0;

int main() {
    cout << "Existem: " << Ponto::get_contador() << " pontos." << endl;

    Ponto p1(0.5, 1.3);
    p1.print_info();

    Ponto p2(3.4, 6.5);
    p2.print_info();

    cout << "Existem " << Ponto::get_contador() << " pontos." << endl;
}