#include "classes2.h"

int main() {
    moto *v1 = new moto();
    carro *v2 = new carro();
    tanque *v3 = new tanque();

    v1->print_info();
    v2->print_info();
    v3->print_info();

    return 0;
}