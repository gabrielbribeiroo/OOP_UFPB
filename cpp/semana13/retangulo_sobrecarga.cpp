#include <iostream>

using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

class retangulo {
    double base;
    double altura;
public:
    retangulo(double b = 0, double a = 0): base(b), altura(a) {}
    ~retangulo() {}

    void print_info() {
        cout << "retangulo(" << base << ", " << altura << ")" << endl;
    }

    double get_base() const {
        return base;
    }

    void set_base(double b) {
        base = b;
    }

    double get_altura() const {
        return altura;
    }

    void set_altura(double a) {
        altura = a;
    }

    retangulo operator+(const retangulo &outro) {
        return retangulo(base + outro.base, altura + outro.altura);
    }

    retangulo operator+(double i) {
        return retangulo(base + i, altura + i);
    }

    friend retangulo operator+(const retangulo &a, const retangulo &b) {
        return retangulo(a.base + b.base, a.altura + b.altura);
    }

    retangulo operator-(const retangulo &outro) {
        return retangulo(base - outro.base, altura - outro.altura);
    }

    retangulo operator-(double i) {
        return retangulo(base - i, altura - i);
    }

    friend retangulo operator-(const retangulo &a, const retangulo &b) {
        return retangulo(a.base - b.base, a.altura - b.altura);
    }

    bool operator==(const retangulo &outro) {
        return (base == outro.base) && (altura == outro.altura);
    }

    bool operator>(const retangulo &outro) {
        return (base * altura) > (outro.base * outro.altura);
    }

    friend bool operator<(const retangulo &a, const retangulo &b) {
        return (a.base * a.altura) < (b.base * b.altura);
    }

    friend ostream &operator<<(ostream &out, const retangulo &r) {
        out << "retangulo(" << r.base << ", " << r.altura << ")";
        return out;
    }

    friend istream &operator>>(istream &in, retangulo &r) {
        in >> r.base >> r.altura;
        return in;
    }
};

int main() {
    retangulo r1(10, 2);
    retangulo r2(5, 10);

    retangulo r3 = r1 + r2;
    retangulo r4 = r1 - r2;

    retangulo r5(10, 2);
    retangulo r6(8, 14);
    retangulo r7;

    cout << "r6: " << r6 << endl;

    cout << "Digite dois numeros reais: " << endl;
    cin >> r7;
    cout << "r7: " << r7 << endl;

    cout << "-----------------" << endl;
    r1.print_info();
    r2.print_info();
    cout << "-----------------" << endl;
    r3.print_info();
    r4.print_info();
    r5.print_info();
    cout << "-----------------" << endl;

    if (r1 > r2) {
        cout << "r1 > r2" << endl;
    }
    else {
        cout << "r2 >= r1" << endl;
    }

    if (r1 == r5) {
        cout << "r1 = r5" << endl;
    }
    else {
        cout << "r1 != r5" << endl;
    }

    if (r4 < r2) {
        cout << "r4 < r2" << endl;
    }
    else {
        cout << "r4 >= r2" << endl;
    }

    return 0;
}