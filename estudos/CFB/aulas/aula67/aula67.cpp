#include <iostream>

using std::cout;
using std::endl;

class veiculo {
private:
    const char *nome;
    const char *cor;
public:
    int vel_max;
    int rodas;

    const char *get_nome() {
        return nome;
    }

    void set_nome(const char *n) {
        nome = n;
    }

    const char *get_cor() {
        return cor;
    }

    void set_cor(const char *c) {
        cor = c;
    }

    virtual void print_info() {
        cout << "Nome....................: " << nome << endl;
        cout << "Cor.....................: " << cor << endl;
        cout << "Rodas...................: " << rodas << endl;
        cout << "Velocidade maxima.......: " << vel_max << endl;
    }
};

// Herança do tipo public
class carro : public veiculo {
public:
    carro() {
        vel_max = 160;
        rodas = 4;
        set_nome("Carro X");
        set_cor("Branco");
    }
};

class moto : public veiculo {
public:
    moto() {
        vel_max = 200;
        rodas = 2;
        set_nome("Moto Y");
        set_cor("Preto");
    }
};

class militar : public veiculo {
public:
    int municao;
    bool armamento;

    militar(bool a, int m): municao(m), armamento(a) {
        vel_max = 150;
        rodas = 6;
        set_nome("Tanque Z");
        set_cor("Verde");

        if (a) {
            municao = m;
        }
        else {
            municao = 0;
        }
    }

    void print_info() override {
        cout << "Nome....................: " << get_nome() << endl;
        cout << "Cor.....................: " << get_cor() << endl;
        cout << "Rodas...................: " << rodas << endl;
        cout << "Velocidade maxima.......: " << vel_max << endl;
        cout << "Armamento...............: " << armamento << endl; 
        cout << "Municao.................: " << municao << endl; 
    }
};

int main() {
    carro v1;
    v1.print_info();
    cout << endl;

    moto v2;
    v2.print_info();
    cout << endl;

    militar v3(200, false);
    v3.print_info();
    cout << endl;

    militar v4(100, true);
    v4.print_info();
    cout << endl;

    return 0;
}