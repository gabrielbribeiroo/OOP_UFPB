#include <iostream>

class motor {
    double cilindradas;
public:
    motor(double c): cilindradas(c) {}
    double get_cilindradas() {
        return cilindradas;
    }
    void set_cilindradas(double c) {
        cilindradas = c;
    }
};

class carro {
    int portas;
    motor m;
public:
    carro(int p, motor &mm): portas(p), m(mm) {}
    int get_portas() {
        return portas;
    }
    void set_portas(int p) {
        portas = p;
    }
    double get_cilindradas() {
        return m.get_cilindradas();
    }
    void set_motor(motor &mm) {
        m = mm;
    }
};

int main(void) {
    motor m1(2.2);
    carro c1(5, m1);

    std::cout << c1.get_cilindradas() << std::endl;

    return 0;
}