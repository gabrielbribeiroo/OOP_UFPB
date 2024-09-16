#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void somador() {
    static auto i = 0; // Utiliza o mesmo endereço de memória (reaproveita)
    i++;
    cout << i << endl;
}

int main() {
    somador();
    somador();
    somador();
    somador();
    somador();
    somador();

    cout << endl;

    register int cont; // Armazena, se possível, a variável em um registrador (acesso mais rápido)
    for (cont=0; cont<=10; cont++) {
        cout << cont << endl;
    }


    cout << endl;
    vector<int>v{10, 20, 30, 40, 50, 60, 70};        
    for (auto it=v.begin(); it!=v.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}