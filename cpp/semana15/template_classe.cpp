#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class num_complex {
    double real;
    double img;
public:
    num_complex(double r, double i): real(r), img(i) {}

    bool operator>(const num_complex &outro) {
        return (real + img) > (outro.real + outro.img);
    }

    num_complex operator+(const num_complex &outro) {
        return num_complex(real + outro.real, img + outro.img);
    }

    friend ostream &operator<<(ostream &out, const num_complex &nc) {
        out << "(" << nc.real << ", " << nc.img << ")";
        return out;
    }
};

template <typename T>
class coisa {
    T atributo;
public:
    coisa (T valor): atributo(valor) {}

    T get_atributo() {
        return atributo;
    }

    void set_atributo(T valor) {
        atributo = valor;
    }
};

int main() {
    coisa<int> c1(15);
    coisa<double> c2(12.45);
    coisa<num_complex> c3(num_complex(0.5, 1.0));
    coisa<string> c4("nome");

    cout << c1.get_atributo() << endl;
    cout << c2.get_atributo() << endl;
    cout << c3.get_atributo() << endl;
    cout << c4.get_atributo() << endl;

    return 0;
}