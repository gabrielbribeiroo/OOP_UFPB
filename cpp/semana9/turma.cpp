#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Pessoa {
    int idade;
    string nome;

public:
    Pessoa(int i, const string &n): idade(i), nome(n) {
        cout << "Pessoa()" << endl;
    }

    ~Pessoa() {
        cout << "~Pessoa()" << endl;
    }

    int get_idade() const {
        return idade;
    }

    void set_idade(int i) {
        idade = i;
    }

    string get_nome() const {
        return nome;
    }

    void set_nome(const string &s) {
        nome = s;  
    }

    void print_info() {
        cout << "pessoa(" << nome << ", " << idade << ")" << endl;
    }
};

class Professor : public Pessoa {
    string titulacao;
    int ano_tit;
public:
    Professor(int i, const string &n, const string &t, int a): Pessoa(i, n), titulacao(t), ano_tit(a) {
        cout << "Professor()" << endl;
    }

    ~Professor() {
        cout << "~Professor()" << endl;
    }

    string get_titulacao() const {
        return titulacao;
    }

    void set_titulacao(const string &tit) {
        titulacao = tit;
    }

    int get_ano_titulacao() const {
        return ano_tit;
    }

    void set_ano_titulacao(int a) {
        ano_tit = a;
    }

    void print_info() {
        cout << "professor(" << get_idade() << ", " << get_nome() << ", ";
        cout << titulacao << ", " << ano_tit << ")" << endl;
    }
};

class Aluno: public Pessoa {
    double cra;
    int matricula;
public:
    Aluno(int i, const string &n, double c, int m): Pessoa(i, n), cra(c), matricula(m) {
        cout << "Aluno()" << endl;
    }

    ~Aluno() { 
        cout << "~Aluno()" << endl;
    }

    double get_cra() const {
        return cra;
    }

    void set_cra(double c) {
        cra = c;
    }

    int get_matricula() const {
        return matricula;
    }

    void set_matricula(int m) {
        matricula = m;
    }

    void print_info() {
        cout << "aluno(" << get_idade() << ", " << get_nome() << ", ";
        cout << cra << ", " << matricula << ")" << endl;
    }
};

class Tecnico: public Pessoa {
    string departamento;
    string funcao;
public:
    Tecnico(int i, const string &n, const string &d, const string &f): Pessoa(i, n), departamento(d), funcao(f) {
        cout << "Tecnico()" << endl;
    }

    ~Tecnico() {
        cout << "~Tecnico()" << endl;
    }

    string get_departamento() const {
        return departamento;
    }

    void set_departamento(int d) {
        departamento = d;
    }

    string get_funcao() const {
        return funcao;
    }

    void set_funcao(const string &f) {
        funcao = f;
    }

    void print_info() {
        cout << "tecnico(" << get_idade() << ", " << get_nome() << ", ";
        cout << departamento << ", " << funcao << ")" << endl;
    }
};

class Turma {
    Professor *prof;
    vector<Aluno*> lista_alunos;
public:
    Turma(Professor *p): prof(p) {
        cout << "Turma()" << endl;
    }

    ~Turma() {
        cout << "~Turma()" << endl;
    }

    Professor *get_professor() const {
        return prof;
    }

    void set_professor(Professor *p) {
        prof = p;
    }

    void add_aluno(Aluno *a) {
        lista_alunos.push_back(a);
    }

    void print_info() {
        cout << "turma:" << endl;
        cout << "professor: ";
        prof->print_info();
        cout << "alunos: ";
        for (auto i = lista_alunos.begin(); i != lista_alunos.end(); ++i) {
            (*i)->print_info(); 
        }
    } 
};

class RH {
    vector<Pessoa*> pessoal;
public:
	void add_pessoa(Pessoa *p) {
		pessoal.push_back(p);
	}
	void print_info() {
		cout << "pessoal: " << endl;
		for (auto i = pessoal.begin(); i != pessoal.end(); ++i) {
            (*i)->print_info();
        }
	}
};

int main() {
    Pessoa p1(38, "Ana Silva");
    Professor pr1(44, "Joao Ferreira", "Doutor", 2008);
    Aluno al1(18, "Maria Fernandes", 9.5, 100123123);
    Tecnico te1(35, "Joao da Silva", "DSC", "Assessor");
    
	RH rh1;

	rh1.add_pessoa(&p1);
	rh1.add_pessoa(&pr1);
	rh1.add_pessoa(&al1);
	rh1.add_pessoa(&te1);

	rh1.print_info();

    /*
    Turma tu1(&pr1);

    pr1.set_idade(41);

    tu1.add_aluno(&al1);
    tu1.print_info();
    */

    /*
    p1.print_info();
    pr1.print_info();
    al1.print_info();
    te1.print_info();
    */

    return 0;
}
