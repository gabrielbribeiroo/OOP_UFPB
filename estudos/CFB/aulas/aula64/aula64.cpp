#include <iostream>
#include <memory>

using namespace std;

class carro {
public:
    int vel_max;
    const char *nome;
    int potencia;
    
    // Lista de inicialização
    carro(const char *n, int p): nome(n), potencia(p) {
        if (p < 100) {
            this->vel_max = 120;
        }
        else if (p < 200) {
            this->vel_max = 220;
        }
        else {
            this->vel_max = 350;
        }
    }
};  

int main() {
    unique_ptr<carro>c1(new carro{"Gabriel", 85});
    cout << "Carro 1: " << c1->nome << " - " << c1->potencia << " - " << c1->vel_max << endl;

    carro c2{"Ventania", 400};
    cout << "Carro 2: " << c2.nome << " - " << c2.potencia << " - " << c2.vel_max << endl;

    return 0;
}