#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Pessoa {
    string nome;
    int idade;
public:
    // Pessoa() {} // Construtor vazio
    Pessoa(const string &n, int i): nome(n), idade(i) {}

    string get_nome() const {
        return nome;
    }

    void set_nome(const string &n) {
        nome = n;
    }

    int get_idade() const {
        return idade;
    }

    void set_idade(int i) {
        idade = i;
    }
};

class Vendedor : public virtual Pessoa {
    double meta;
public:
    Vendedor(const string &n, int i, double m): Pessoa(n, i), meta(m) {}

    double get_meta() const {
        return meta;
    }

    void set_meta(double m) {
        meta = m;
    }

    void print_info() {
        cout << "vendedor(" << meta << ")" << endl; 
    }
};

class Gerente : public virtual Pessoa {
    string departamento;
public:
    Gerente(const string &n, int i, const string &d): Pessoa(n, i), departamento(d) {}

    string get_departamento() const {
        return departamento;
    }

    void set_departamento(const string &d) {
        departamento = d;
    }

    void print_info() {
        cout << "gerente(" << departamento << ")" << endl;
    }
};

// Herança múltipla pode possuir diferentes tipos entre elas
class Vendedor_Gerente : public Vendedor, public Gerente {
public:
    Vendedor_Gerente(const string &n, int i, double m, const string &d): Pessoa(n, i), Vendedor(n, i, m), Gerente(n, i, d) {}

    void print_info() {
        cout << "--------------------------" << endl;
        cout << "vendedor_gerente:" << endl;
        Vendedor::print_info();
        Gerente::print_info();
        cout << "--------------------------" << endl;
    }
};

int main() {
    Vendedor_Gerente vg1("Joao", 30, 5000, "ELETRO");

    // vg1.set_nome("Jose");
    
    cout << "Nome: " << vg1.get_nome() << endl;
    cout << "Idade: " << vg1.get_idade() << endl;

    vg1.print_info();
    vg1.Vendedor::print_info();
    vg1.Gerente::print_info();

    return 0;
}