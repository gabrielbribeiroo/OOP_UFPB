#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class complex {
    double real;
    double img;
public:
    complex(double r, double i): real(r), img(i) {}

    bool operator>(const complex &outro) {
        return (real + img) > (outro.real + outro.img);
    }

    complex operator+(const complex &outro) {
        return complex(real + outro.real, img + outro.img);
    }

    complex operator*(const complex &outro) {
        return complex(real * outro.real, img * outro.img);
    }

    friend ostream &operator<<(ostream &out, const complex &nc) {
        out << "(" << nc.real << ", " << nc.img << ")";
        return out;
    }
};

template <typename T>
T square(T x) {
    return (x*x);
}

template <>
char square(char c) {
    cout << "Nao faz sentido elevar um char ao quadrado." << endl;
    return c;
}

int main() {
    cout << square(5) << endl;
    cout << square(10.2) << endl;
    cout << square(complex(10.5, 0.8)) << endl;
    cout << square('a') << endl;

    return 0;
}