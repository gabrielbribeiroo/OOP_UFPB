#include <iostream>
#include <memory>

using namespace std;

class carro {
public:
    int vel = 0;
    int get_vel() {
        return vel;
    }
    void set_vel(int v) {
        this->vel = v;
    }
};


int main() {
    unique_ptr<carro>c1(new carro);
    unique_ptr<carro>c2(new carro);
    c1->set_vel(10);
    c2->set_vel(5);
    cout << "Velocidade c1: " << c1->get_vel() << endl;
    cout << "Velocidade c2: " << c2->get_vel() << endl;

    return 0;
}