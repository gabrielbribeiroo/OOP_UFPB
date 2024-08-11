#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Aviao {
public:
    int vel = 0;
    int vel_max;
    string tipo;
    void ini(int tp);
};

void Aviao::ini(int tp) {
    // 1=Jato; 2=Monomotor; 3=Planador
    switch (tp) {
        case 1:
            this->vel_max = 800;
            this->tipo == "Jato";
            break;
        case 2:
            this->vel_max = 350;
            this->tipo == "Monomotor";
            break;
        case 3:
            this->vel_max = 180;
            this->tipo == "Planador";
            break;
        default:
            this->vel_max = 0;
            break;
    }
}

int main(void) {
    Aviao *av1 = new Aviao();
    Aviao *av2 = new Aviao();

    av1->ini(1);
    av2->ini(2);

    cout << av1->vel_max << endl;
    cout << av2->vel_max << endl;

    return 0;
}