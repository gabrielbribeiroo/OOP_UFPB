#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> produtos = {"mouse", "teclado", "monitor", "gabinete", "cx.som"};

    // it = produtos.begin(); // Aponta para o primeiro termo
    // it = produtos.end()-1; // Aponta para o último termo

    // advance(it, 2); // Navega para as posições a frente 

    // cout << *next(it, 3) << endl; // Avança determinadas casas à direita
    // cout << *prev(it, 1) << endl; // Retorna determinadas posições de elementos 

    for (vector<string>::iterator it=produtos.begin(); it!=produtos.end();  it++) {
        cout << *it << endl; // Exibe todos os elementos do vetor
    }

    return 0;
}