#include <iostream>

using namespace std;

class carro {
private:
    int vel_max;
    const char *nome;
public:
    int potencia;
    int get_velmax() {
        return vel_max;
    }
    const char *get_nome() {
        return nome;    
    }
    // Sobrecarga de métodos construtores
    carro() {
        vel_max = 120;
        potencia = 85;
        nome = "Popular";
    }
    carro(int pt, const char *no): nome(no), potencia(pt) {
        if (pt < 100) {
            vel_max = 120;
        }
        else if (pt < 200) {
            vel_max = 240;
        }
        else {
            vel_max = 360;
        }
    }
};

int main() {
    carro c1;
    cout << c1.get_nome() << " - " << c1.potencia << " - " << c1.get_velmax() << endl;

    carro c2{180, "Luxo"};
    cout << c2.get_nome() << " - " << c2.potencia << " - " << c2.get_velmax() << endl;

    carro c3{300, "Esportivo"};
    cout << c3.get_nome() << " - " << c3.potencia << " - " << c3.get_velmax() << endl;
    
    return 0;
}