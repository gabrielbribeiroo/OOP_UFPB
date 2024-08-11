#ifndef CLASSES2_H
#define CLASSES2_H

#include <iostream>

using std::cout;
using std::endl;

class veiculo {
public:
    int vel;
    int blind;
    int rodas;
    void set_tipo(int tp);
    void set_velmax(int vm);
    void set_arma(bool ar);
    void print_info();
private:
    int tipo; // 1 = Moto; 2 = Carro; 3 = Caminhão; 4 = Tanque
    int vel_max;
    bool arma;
};

void veiculo::print_info() {
    cout << "Tipo de veiculo....: " << tipo << endl;
    cout << "Velocidade maxima..: " << vel_max << endl;
    cout << "Quantidade de rodas: " << rodas << endl;
    cout << "Blindagem..........: " << blind << endl;
    cout << "Armamento..........: " << arma << endl;
    cout << "--------------------------------" << endl;
}

void veiculo::set_tipo(int tp) {
    tipo = tp;
}

void veiculo::set_velmax(int vm) {
    vel_max = vm;
}

void veiculo::set_arma(bool ar) {
    arma = ar;
}

// A classe moto (classe filho) herda a classe veiculo (classe pai), incluindo todos os seus métodos e propriedades
class moto: public veiculo {
public:
    moto();
};

// Método construtor (possui o mesmo nome da classe)
moto::moto() {
    vel = 0;
    blind = 0;
    rodas = 2;
    // tipo = 1; // ERRO! (Por ser uma instância privada, só poderia ser alterada dentro da classe veiculo)
    set_tipo(1);
    set_velmax(120);
    set_arma(false);
}

// A classe carro (classe filho) herda a classe veiculo (classe pai), incluindo todos os seus métodos e propriedades
class carro: public veiculo {
public:
    carro();
};

carro::carro() {
    vel = 0;
    blind = 0;
    rodas = 4;
    set_tipo(2);
    set_velmax(180);
    set_arma(false);
}

// A classe tanque (classe filho) herda a classe veiculo (classe pai), incluindo todos os seus métodos e propriedades
class tanque: public veiculo {
public:
    tanque();
};

tanque::tanque() {
    vel = 0;
    blind = 1;
    rodas = 8;
    set_tipo(4);
    set_velmax(200);
    set_arma(true);
}

#endif // CLASSES2_H