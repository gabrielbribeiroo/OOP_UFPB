#include <iostream>

using namespace std;

class veiculo {
private: 
/*
Acesso somente dentro da classe
*/
    int vel_max;
    int potencia;
public:
/* 
Variáveis que podem ser acessadas dentro e fora da classe, por membros herdados ou quando é declarada dentro de outra classe
*/
    int rodas;
    const char *nome;
protected:
/*
Acesso tanto dentro quanto fora da classe, além de poder ser acessada por classes que estão herdando a classe base, mas não quando declarada em objetos de outra classe
*/
    int portas;
    const char *cor;
};

// A classe carro herda a classe veiculo
class carro:public veiculo {
public:
    carro() {
        // vel_max = 180; // ERRO! Acesso é negado por ser private e estar fora da classe base
        // potencia = 150; // ERRO! Acesso é negado por ser private e estar fora da classe base
        rodas = 4;
        nome = "Carro";
        portas = 4; 
        cor = "Vermelho";

        // cout << vel_max << endl; // ERRO! Acesso é negado por ser private e estar fora da classe base
        // cout << potencia << endl; // ERRO! Acesso é negado por ser private e estar fora da classe base
        cout << rodas << endl;
        cout << nome << endl;
        cout << portas << endl;
        cout << cor << endl;
    }
};

class moto {
public:
    carro c;

    moto() {
        // vel_max = 250; // ERRO! Acesso é negado por ser privado
        // potencia = 500; // ERRO! Acesso é negado por ser privado
        c.rodas = 2;
        c.nome = "Moto";
        // portas = 0; // ERRO! Acesso é negado por ser protegido
        // cor = "Preto"; // ERRO! Acesso é negado por ser protegido

        // cout << vel_max << endl; // ERRO! Acesso é negado por ser privado
        // cout << potencia << endl; // ERRO! Acesso é negado por ser privado
        cout << c.rodas << endl;
        cout << c.nome << endl;
        // cout << portas << endl; // ERRO! Acesso é negado por ser protegido
        // cout << cor << endl; // ERRO! Acesso é negado por ser protegido
    }
};

int main() {
    carro v1;
    cout << endl << endl;
    moto v2;

    return 0;
}