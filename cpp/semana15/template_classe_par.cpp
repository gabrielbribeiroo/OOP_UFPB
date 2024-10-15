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

    friend ostream &operator<<(ostream &out, const complex &nc) {
        out << "(" << nc.real << ", " << nc.img << ")";
        return out;
    }
};

template <typename T, typename U>
class my_pair {
    T first;
    U second;
public:
    my_pair(T f, U s): first(f), second(s) {}

    T get_first() {
        return first;
    }

    void set_first(const T &f) {
        first = f;
    }

    U get_second() {
        return second;
    }

    void set_second(const U &s) {
        second = s;
    }

    friend ostream &operator<<(ostream &out, const my_pair &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }
};

int main() {
    my_pair<int, double> p1(100, 0.8);
    my_pair<string, complex> p2("nome", complex(6.7, 8.9));

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}