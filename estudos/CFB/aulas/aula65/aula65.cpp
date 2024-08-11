#include <iostream>
#include <memory>

using namespace std;

class carro {
private:
    int vel_max;
    /*
    void set_velmax(int vm) {
        this->vel_max = vm;
    }
    */
public:
    const char *nome;
    int potencia;

    int get_velmax() {
        return this->vel_max;
    }
    
    // Lista de inicialização
    carro(const char *n, int p): nome(n), potencia(p) {
        if (p < 100) {
            // this->set_velmax(120);
            this->vel_max = 120;
        }
        else if (p < 200) {
            // this->set_velmax(220);
            this->vel_max = 220;
        }
        else {
            // this->set_velmax(350);
            this->vel_max = 350;
        }
    }
};  

int main() {
    unique_ptr<carro>c1(new carro{"Gabriel", 85});
    cout << "Carro 1: " << c1->nome << " - " << c1->potencia << " - " << c1->get_velmax() << endl;

    carro c2{"Ventania", 400};
    cout << "Carro 2: " << c2.nome << " - " << c2.potencia << " - " << c2.get_velmax() << endl;

    return 0;
}