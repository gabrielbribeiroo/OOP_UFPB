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

template <typename T1, typename T2>
class container {
    T1 data1;
    T2 data2;
public:
    container(T1 d1, T2 d2): data1(d1), data2(d2) {}

    friend ostream &operator<<(ostream &out, const container &c) {
        out << "(" << c.data1 << ", " << c.data2 << ")";
        return out;
    }
};

template <typename T>
class container<T, T> {
    T data;
public:
    container(T d): data(d) {}

    friend ostream &operator<<(ostream &out, const container &c) {
        out << "[" << c.data << "]" << endl;
        return out;
    }
};

int main() {
    container<int, double> c1(20, 100.5);
    container<string, complex> c2("nome", complex(0.5, 2.2));
    container<string, string> c3("outro nome");

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;

    return 0;
}