#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::exception;

double divide(double n10, double n20) {
    if (n20 == 0) {
        throw "Erro de divisao por ZERO"; // Lança a mensagem de erro
    }
    if (n10 >= 10) {
        throw "N1 precisa ser menor que 10";
    }
    return n10/n20;
}

int main() {
    double n1, n2;

    cin >> n1 >> n2;

    // Identifica o erro
    try {
        cout << divide(n1, n2) << endl;
    }
    // Trata o erro
    catch (const char *e) {
        cout << "ERRO: " << e << endl;
    }

    return 0;
}