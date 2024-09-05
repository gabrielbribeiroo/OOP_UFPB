/*
|-------------------------------------------------------------------------------------------------------------|
|      ENCAPSULAMENTO (ASC.)       |              HERANÇA              |          ENCAPSULAMENTO (DESC.)      |
|-------------------------------------------------------------------------------------------------------------|
|           public                 |                                   |              protected               |
|           protected              |             protected             |              protected               |
|           private                |                                   |              ---------               |
|-------------------------------------------------------------------------------------------------------------|
*/

#include <iostream>

using std::cout;
using std::endl;

class Veiculo {
protected:
    double velocidade;
public:
    Veiculo(double v): velocidade(v) {} // Construtor
    ~Veiculo() {} // Destrutor

    double get_velocidade() const {
        return velocidade;
    }

    void set_velocidade(double v) {
        velocidade = v;
    }
};

class Carro : protected Veiculo {
public:
    Carro(double v): Veiculo(v) {} // Construtor
    ~Carro() {} // Destrutor

    void mostrar_velocidade() {
        cout << "Velocidade = " << velocidade << endl; 
    }
};

int main() {
    Carro c1(60); 

    // c1.set_velocidade(80); // ERRO (Não pode acessar herança protected pelo objeto)
    c1.mostrar_velocidade();

    // Veiculo *pv1 = &c1;

    return 0;
}