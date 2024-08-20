#include "medalha.h" // Inclui o cabeçalho correspondente
#include <iostream> // Inclui a biblioteca para operações de entrada/saída

using std::cout;
using std::endl;
using std::string;

Medalha::Medalha(const string &t, int ano, std::unique_ptr<Atleta> a, std::unique_ptr<Modalidade> m) 
    : tipo(t), ano(ano), atleta(std::move(a)), modalidade(std::move(m)) {
    cout << "Medalha: " << tipo << " criada!" << endl; // Construtor para inicializar os atributos da medalha
}

Medalha::~Medalha() {
    cout << "Medalha: " << tipo << " destruida!" << endl; // Destrutor para liberar os recursos da medalha
} 

// Leitura e modificação do tipo da medalha
string Medalha::get_tipo() const {
    return tipo;
}
void Medalha::set_tipo(const string &t) {
    this->tipo = t;
}

// Leitura e modificação do ano da conquista da medalha
int Medalha::get_ano() const {
    return ano;
}
void Medalha::set_ano(int ano) {
    this->ano = ano;
}

// Leitura e modificação do atleta que conquistou a medalha
Atleta *Medalha::get_atleta() const {
    return atleta.get();
}
void Medalha::set_atleta(std::unique_ptr<Atleta> a) {
    this->atleta = std::move(a);
}

// Leitura e modificação da modalidade, na qual a medalha foi conquistada
Modalidade *Medalha::get_modalidade() const {
    return modalidade.get();
}
void Medalha::set_modalidade(std::unique_ptr<Modalidade> m) {
    this->modalidade = std::move(m);
}

// Exibe as informações acerca da medalha conquistada
void Medalha::print_info() {
    std::cout << "Medalha: " << tipo << ", Ano: " << ano << std::endl;
    atleta->print_info();
    modalidade->print_info();
}