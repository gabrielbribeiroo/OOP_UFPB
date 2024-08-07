#include "autor.h"
#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;

autor::autor(const string &n, const string &d, const string &na) : nome(n), data_nascimento(d), nacionalidade(na) {
    cout << "Autor: " << nome << " criado!" << endl;
}

autor::~autor() {
    cout << "Autor: " << nome << " destruido!" << endl;
}

string autor::get_nome() {
    return nome;
}

void autor::set_nome(const string &n) {
    nome = n;
}

string autor::get_data_nascimento() {
    return data_nascimento;
}

void autor::set_data_nascimento(const string &d) {
    data_nascimento = d;
}

string autor::get_nacionalidade() {
    return nacionalidade;
}

void autor::set_nacionalidade(const string &na) {
    nacionalidade = na;
}

void autor::print_info() {
    cout << "Nome: " << nome << endl;
    cout << "Data de nascimento: " << data_nascimento << endl;
    cout << "Nacionalidade: " << nacionalidade << endl;
}