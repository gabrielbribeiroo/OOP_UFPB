#include <iostream>

int soma(int a, int b) {
    return a+b;
}

int soma(int a, int b, int c) {
    return a+b+c;
}

double soma(double a, double b) {
    return a+b;
}

int main(void) {
    std::cout << "Soma de 2 inteiros: ";
    std::cout << soma(3, 4) << std::endl;
    std::cout << "Soma de 3 inteiros: ";
    std::cout << soma(1, 2, 3) << std::endl;
    std::cout << "Soma de 2 numeros reais: ";
    std::cout << soma(10.5, 0.9) << std::endl;
}