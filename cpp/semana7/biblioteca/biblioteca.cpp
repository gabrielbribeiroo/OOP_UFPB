#include <iostream>
#include <string>
#include <memory>
#include "biblioteca.h"

using std::cout;
using std::endl;
using std::string;

#define TAMANHO_BIBLIOTECA 100

biblioteca::biblioteca(const string &n, const string &e) : nome(n), endereco(e) {
    num_livros = 0;
    cout << "Biblioteca: " << nome << " criada!" << endl;
}

biblioteca::~biblioteca() {
    cout << "Biblioteca: " << nome << " destruida!" << endl;
}

string biblioteca::get_nome() {
    return nome;
}

void biblioteca::set_nome(const string &n) {
    nome = n;
}

string biblioteca::get_endereco() {
    return endereco;
}

void biblioteca::set_endereco(const string &e) {
    endereco = e;
}

std::shared_ptr<livro> biblioteca::get_livro(int pos) {
    return colecao_livros[pos];
}

void biblioteca::add_livro(std::shared_ptr<livro> l) {
    if (num_livros < TAMANHO_BIBLIOTECA) {
        colecao_livros[num_livros] = l;
        num_livros++;
    } 
    else {
        cout << "Biblioteca cheia!" << endl;
    }
}

int biblioteca::get_num_livros() {
    return num_livros;
}

void biblioteca::print_info() {
    cout << "Nome: " << nome << endl;
    cout << "Endereco: " << endereco << endl;
    cout << "Colecao de livros: " << endl;
    for (int i=0; i<num_livros; i++) {
        colecao_livros[i]->print_info();
    }
}