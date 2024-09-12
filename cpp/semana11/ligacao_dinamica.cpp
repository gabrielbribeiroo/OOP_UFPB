// Ligação dinâmica acontece apenas com subtipagem (herança pública)

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Pessoa {
    string nome;
    int idade;
    string endereco;
public:
    Pessoa(const string &n, int i, const string &e): nome(n), idade(i), endereco(e) {} 

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

    string get_endereco() const {
        return endereco;
    }

    void set_endereco(const string &e) {
        endereco = e;
    }

    virtual void print_info() {
        cout << "pessoa: " << nome << ", " << idade << ", " << endereco << endl;
    }
};

class Estudante : public Pessoa {
    double cra;
public:
    Estudante(const string &n, int i, const string &e, double c): Pessoa(n, i, e), cra(c) {}

    double get_cra() const {
        return cra;
    }

    void set_cra(double c) {
        cra = c;
    }

    void print_info() {
        cout << "------------------------------------------" << endl;
        cout << "estudante: " << cra << endl;
        Pessoa::print_info();
        cout << "------------------------------------------" << endl;
    }
};

class Professor : public Pessoa {
    string categoria;
public:
    Professor(const string &n, int i, const string &e, const string &c): Pessoa(n, i, e), categoria(c) {}

    string get_categoria() const {
        return categoria;
    }

    void set_categoria(const string &c) {
        categoria = c;
    } 

    void print_info() {
        cout << "------------------------------------------" << endl;
        cout << "professor: " << categoria << endl;
        Pessoa::print_info();
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    Professor p1("Ana Silva", 39, "R. S/N, 33", "Titular");
    Estudante e1("Joao Fernandes", 18, "R. X, 99", 8.5);
    Estudante e2("Maria Ferreira", 19, "R. Y, 66", 9.0);
    Estudante e3("Jose da Silva", 20, "R. Z, 44", 8.0);

    Pessoa *turma[4];

    turma[0] = &p1;
    turma[1] = &e1;
    turma[2] = &e2;
    turma[3] = &e3;

    double soma_idade;

    for (int i=0; i<4; i++) {
        soma_idade += turma[i]->get_idade();
    }

    cout << "Media das idades = " << soma_idade/4 << endl;

    int numero;

    cout << "Digite o indice desejado [0-3]: ";
    cin >> numero;

    turma[numero]->print_info();

    return 0;
}