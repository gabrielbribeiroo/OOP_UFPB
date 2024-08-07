#include "livro.h"
#include <iostream>

using std::cout;
using std::string;
using std::endl;

livro::livro(const string &t, int a, std::shared_ptr<autor> au): titulo(t), ano(a), autor_livro(au) {
    cout << "Livro: " << titulo << " criado!" << endl;
}

livro::~livro() {
    cout << "Livro: " << titulo << " destruido!" << endl;
}

string livro::get_titulo() {
    return titulo;
}

void livro::set_titulo(const string &t) {
    titulo = t;
}

int livro::get_ano() {
    return ano;
}

void livro::set_ano(int a) {
    ano = a;
}

std::shared_ptr<autor> livro::get_autor() {
    return autor_livro;
}

void livro::set_autor(std::shared_ptr<autor> au) {
    autor_livro = au;
}

void livro::print_info() {
    cout << "*********************************" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Ano: " << ano << endl;
    cout << "Autor: " << endl; 
    autor_livro->print_info();
}
