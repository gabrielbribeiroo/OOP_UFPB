#include <iostream>
#include "classes.h"

using std::cout;
using std::endl;

int main(void) {
    veiculo *v1 = new veiculo(1);
    veiculo *v2 = new veiculo(2);
    veiculo *v3 = new veiculo(3);

    // v1->set_ligado(0);
    v2->set_ligado(1);
    // v3->set_ligado(0);

    cout << "Velocidade maxima: " << v1->get_VelMax() << endl;
    cout << "Velocidade maxima: " << v2->get_VelMax() << endl;
    cout << "Velocidade maxima: " << v3->get_VelMax() << endl;

    if (v1->get_ligado()) {
        cout << "Veiculo 1 esta ligado." << endl;
    }
    else {
        cout << "Veiculo 1 esta desligado." << endl;
    }

    if (v2->get_ligado()) {
        cout << "Veiculo 2 esta ligado." << endl;
    } 
    else {
        cout << "Veiculo 2 esta desligado." << endl;
    }

    if (v3->get_ligado()) {
        cout << "Veiculo 3 esta ligado." << endl;
    }
    else {
        cout << "Veiculo 3 esta desligado." << endl;
    }

    return 0; 
}