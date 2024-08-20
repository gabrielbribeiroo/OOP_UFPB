#include "Pais.h" // Inclui o cabeçalho correspondente
#include <iostream> // Inclui a biblioteca para operações de entrada/saída

using std::cout;
using std::endl;
using std::string;

Pais::Pais(const string &n, const string &c) : nome(n), continente(c) {
    cout << "Pais: " << nome << " criado!" << endl; // Construtor para inicializar os atributos do país
}

Pais::~Pais() {
    cout << "Pais: " << nome << " destruido!" << endl; // Destrutor para liberar os recursos do país
}

// Retorna e modifica o nome do país
string Pais::get_pais() const {
    return nome;
}
void Pais::set_pais(const string &n) {
    this->nome = n;
}

// Retorna e modifica o nome do continente
std::string Pais::get_continente() const {
    return continente;
}
void Pais::set_continente(const std::string &c) {
    this->continente = c;
}

// Exibe as informações do país
void Pais::print_info() {
    cout << "Pais: " << nome << endl;
    cout << "Continente: " << continente << endl;
}