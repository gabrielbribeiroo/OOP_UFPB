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
void print(T value) {
    cout << value << endl;
}

template <typename T, typename... Args>
void print(T first, Args... args) {
    cout << first << " ";
    print(args...);
}

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

int main() {
    print("Hello world!");
    print(1.5, 10, "Hello", 'A', complex(10.5, 0.6), true); 
    cout << sum(1, 2, 3, 4, 5) << endl;
    cout << sum(0.1, 0.2, 0.3, 0.4, 0.5) << endl;
    cout << sum(complex(0.1, 0.2), complex(0.3, 0.4)) << endl;
      
    return 0;
}