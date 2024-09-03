#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Conta {
protected:
    double saldo;
public:
    Conta(double s): saldo(s) {} // Construtor
    ~Conta() {} // Destrutor

    void altera_saldo_mes() {

    }

    void sacar(double valor) {
        saldo -= valor;
    }

    void depositar(double valor) {
        saldo += valor;
    }

    void print_info() {
        cout << "Saldo: " << saldo << endl;
    }
};

class Conta_corrente : public Conta {
private:
    double limite;
    double valor_manutencao;
public:
    Conta_corrente(double s, double l, double vm): Conta(s), limite(l), valor_manutencao(vm) {} // Construtor
    ~Conta_corrente() {} // Destrutor

    void altera_saldo_mes() {
        saldo -= valor_manutencao;
    }

    void sacar(double valor) {
        if (valor <= (saldo+limite)) {
            saldo -= valor;
        }
        else {
            cout << "Saldo insuficiente!" << endl;
        }
    }

    void depositar(double valor) {
        saldo += valor;
    }
};

class Conta_poupanca : public Conta {
private:
    double rendimento;
public:
    Conta_poupanca(double s, double r): Conta(s), rendimento(r) {} // Construtor
    ~Conta_poupanca() {} // Destrutor

    void altera_saldo_mes() {
        saldo += (saldo*rendimento);
    }

    void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
        }
        else {
            cout << "Saldo insuficiente!" << endl;
        }
    }

    void depositar(double valor) {
        saldo += valor;
    }
};

int main() {
    Conta_corrente cc1(1000, 200, 20);
    Conta_poupanca cp1(500, 0.01);

    Conta *pc1;
    Conta *pc2;

    pc1 = &cc1;
    pc2 = &cp1;

    cc1.altera_saldo_mes();
    cp1.altera_saldo_mes();

    pc1->print_info();
    pc2->print_info();

    return 0;
}