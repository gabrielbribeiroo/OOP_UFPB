#include "atleta.h" // Inclui o cabeçalho correspondente
#include <iostream> // Inclui a biblioteca para operações de entrada/saída

using std::cout;
using std::endl;
using std::string;

Atleta::Atleta(const string &n, std::unique_ptr<Pais> p, std::unique_ptr<Modalidade> m) 
    : nome(n), pais(std::move(p)), modalidade(std::move(m)) {
    cout << "Atleta: " << nome << " criado!" << endl; // Construtor para inicializar o nome do atleta, o país e a modalidade
} 

Atleta::~Atleta() {
    cout << "Atleta: " << nome << " destruido!" << endl; // Destrutor para liberar os recursos do atleta
} 

// Leitura e modificação do nome do atleta
string Atleta::get_nome() const {
    return nome;
}
void Atleta::set_nome(const string &n) {
    this->nome = n;
}

// Leitura e modificação do país do atleta
Pais *Atleta::get_pais() const {
    return pais.get();
}
void Atleta::set_pais(std::unique_ptr<Pais> p) {
    this->pais = std::move(p);
}

// Leitura e modificação da modalidade do atleta
Modalidade *Atleta::get_modalidade() const {
    return modalidade.get();
}
void Atleta::set_modalidade(std::unique_ptr<Modalidade> m) {
    this->modalidade = std::move(m);
}

// Exibe as informações do atleta
void Atleta::print_info() {
    cout << "Atleta: " << nome << endl;
    pais->print_info();
    modalidade->print_info();
}