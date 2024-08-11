#ifndef AVIAO_H
#define AVIAO_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class aviao {
public:
    int vel=0;
    int vel_max;
    string tipo;
    aviao(int tp);
    void print_info();
};

aviao::aviao(int tp) {
    // 1=Jato; 2=Monomotor; 3=Planador
    switch (tp) {
        case 1:
            vel_max = 800;
            tipo = "Jato";
            break;
        case 2:
            vel_max = 350;
            tipo = "Monomotor";
            break;
        case 3:
            vel_max = 180;
            tipo = "Planador";
            break;
        default:
            vel_max = 0;
            break;
    }
}

void aviao::print_info() {
    cout << "Tipo.............: " << tipo << endl;
    cout << "Velocidade maxima: " << vel_max << endl;
    cout << "Velocidade atual.: " << vel << endl;
    cout << "--------------------------------" << endl;
}

#endif // AVIAO_H