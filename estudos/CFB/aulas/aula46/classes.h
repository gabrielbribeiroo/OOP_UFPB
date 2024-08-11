#ifndef CLASSES_H
#define CLASSES_H

#include <string>

class veiculo {
public:
    int vel;
    int tipo;
    veiculo(int tp);
    int get_VelMax();
    bool get_ligado();
    void set_ligado(int l);
private:
    void set_VelMax(int vm);
    std::string nome;
    int vel_max;
    bool ligado;
};

bool veiculo::get_ligado() {
    return ligado;
}   

void veiculo::set_ligado(int l) {
    // Verifica se l é igual a 1
    if (l) {
        ligado = true;
    }
    else if (l == 0) {
        ligado = false;
    }
}

int veiculo::get_VelMax() {
    return vel_max;
}

void veiculo::set_VelMax(int vm) {
    vel_max = vm;
}

veiculo::veiculo(int tp) {
    // 1 = Carro; 2 = Avião ; 3 = Navio
    switch (tp) {
        case 1:
            nome = "Carro";   
            set_VelMax(200);                    
            break;
        case 2:
            nome = "Aviao";
            set_VelMax(800);  
            break;
        case 3:
            nome = "Navio";
            set_VelMax(120);  
            break;
        default:
            break;
    }
    set_ligado(0);
}

#endif // CLASSES_H