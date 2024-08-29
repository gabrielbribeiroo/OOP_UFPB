#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Pessoa {
private:
    string nome;
    string cpf;
protected:
    double salario;
public:
    Pessoa(const string &n, const string &c, double s): nome(n), cpf(c), salario(s) {} // Construtor
    ~Pessoa() {} // Destrutor

    string get_nome() const {
        return nome;
    }

    void set_nome(const string &n) {
        nome = n;
    }

    string get_cpf() const {
        return cpf;
    }

    void set_cpf(const string &c) {
        cpf = c;
    } 

    double get_salario() const {
        return salario;
    }
};

class Funcionario : public Pessoa {
private:
    int carga_horaria;
    string departamento;
public: 
    Funcionario(const string &n, const string &c, double s, int ch, const string &d): Pessoa(n, c, s), carga_horaria(ch), departamento(d) {} // Construtor
    ~Funcionario() {} // Destrutor

    int get_carga_horaria() const {
        return carga_horaria;
    }

    void set_carga_horaria(int ch) {
        carga_horaria = ch;
    }

    string get_departamento() const {
        return departamento;
    }

    void set_departamento(const string &d) {
        departamento = d;
    }

    void modifica_salario() {
        salario *= 1.3;
    }
};

class Gerente : public Pessoa {
private:
    double bonus;
    string projeto;
public:
    Gerente(const string &n, const string &c, double s, double b, const string &p): Pessoa(n, c, s), bonus(b), projeto(p) {} // Construtor
    ~Gerente() {} // Destrutor

    double get_bonus() const {
        return bonus;
    }

    void set_bonus(double b) {
        bonus = b;
    }

    string get_projeto() const {
        return projeto;
    }

    void set_projeto(const string &p) {
        projeto = p;
    }

    void modifica_salario() {
        salario = salario*2 + bonus;
    }
};

int main() {
    Funcionario func1("Joao da Silva", "1234", 2000, 40, "Informatica");
    Gerente ger1("Ana Fernandes", "5678", 4000, 1000, "Software");

    cout << "Salario atual do funcionario: " << func1.get_salario() << endl;
    cout << "Salario atual do gerente: " << ger1.get_salario() << endl << endl; 

    func1.modifica_salario();
    ger1.modifica_salario();

    cout << "Novo salario do funcionario: " << func1.get_salario() << endl;
    cout << "Novo salario do gerente: " << ger1.get_salario() << endl;

    return 0;
}