#include <iostream>

using std::cout;
using std::endl;
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
T max_value(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T sum(T a, T b) {
    return a+b;
}

int main() {
    num_complex nc1(0.5, 1.2);
    num_complex nc2(2.3, 0.2);

    double x = sum(10.5, 23.67);
    cout << x << endl;

    num_complex nc3 = sum(nc1, nc2);
    cout << nc3 << endl;

    cout << max_value(3, 7) << endl;
    cout << max_value(10.2, 2.38) << endl;
    cout << max_value('a', 'z') << endl;
    cout << max_value(nc1, nc2);

    return 0;
}