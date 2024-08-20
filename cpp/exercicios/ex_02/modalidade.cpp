#include "modalidade.h" // Inclui o cabeçalho correspondente
#include <iostream> // Inclui a biblioteca para operações de entrada/saída

using std::cout;
using std::endl;
using std::string;

Modalidade::Modalidade(const string &n, bool i) : nome(n), individual(i) {
    cout << "Modalidade: " << nome << " criada!" << endl; // Construtor para inicializar o nome da modalidade e o seu respectivo tipo
}

Modalidade::~Modalidade() {
    cout << "Modalidade: " << nome << " destruida!" << endl; // Destrutor para liberar os recursos da modalidade
}

// Leitura e modificação da modalidade esportiva
string Modalidade::get_modalidade() const {
    return nome;
}
void Modalidade::set_modalidade(const string &n) {
    this->nome = n;
}

// Leitura e modificação do tipo da modalidade
bool Modalidade::is_individual() const {
    return individual;
}
void Modalidade::set_individual(bool i) {
    this->individual = i;
}

// Exibe as informações da modalidade
void Modalidade::print_info() const{
    cout << "Modalidade: " << nome << endl;
    cout << "Tipo: " << (individual ? "Individual" : "Coletiva") << endl;
}

