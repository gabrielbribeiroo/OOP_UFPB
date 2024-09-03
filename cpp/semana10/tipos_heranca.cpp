#include <iostream>

using std::cout;
using std::endl;

class Base {
private:
    int valor;
public:
    Base(int v): valor(v) {}

    int get_valor() const {
        return valor;
    }

    void set_valor(int v) {
        valor = v;
    }
};

class Derivada : public Base {
public:
    Derivada(int v): Base(v) {}
};

int main() {
    Base b1(10);
    Base *pb1;
    Derivada d1(20);

    pb1 = &d1;

    cout << b1.get_valor() << endl;
    // cout << d1.get_valor() << endl; // Herança privada ou protegida não permite subtipagem (herança múltipla)

    return 0;
}