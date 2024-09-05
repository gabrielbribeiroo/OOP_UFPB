/*
|-------------------------------------------------------------------------------------------------------------|
|      ENCAPSULAMENTO (ASC.)       |              HERANÇA              |          ENCAPSULAMENTO (DESC.)      |
|-------------------------------------------------------------------------------------------------------------|
|           public                 |                                   |               private                |
|           protected              |              private              |               private                |
|           private                |                                   |              ---------               |
|-------------------------------------------------------------------------------------------------------------|
*/

#include <iostream>

using std::cout;
using std::endl;

class Pessoa {
private:
    int idade;
public:
    Pessoa(int i): idade(i) {} // Construtor

    int get_idade() const {
        return idade;
    }

    void set_idade(int i) {
        idade = i;
    }

    void print_info() {
        cout << "Idade: " << idade << endl;
    }
};

// Herança padrão: private 
class Estudante : Pessoa {
public:
    Estudante(int i): Pessoa(i) {} // Construtor

    void estudar() {
        cout << "estudar()" << endl;
        print_info();
        cout << "fim estudar()" << endl;
    }
};

int main() {
    Pessoa *pp1;
    Estudante e1(20);

    // pp1 = &e1; // ERRO! (Estudante não é subtipo de pessoa)
    // e1.print_info(); // ERRO! (Objetos, advindos de herança privada, não acessam métodos que se tornaram privados)
    
    e1.estudar(); 

    return 0;
}