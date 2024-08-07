#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <memory>
#include "livro.h"

using std::string;

#define TAMANHO_BIBLIOTECA 100

class biblioteca {
    string nome;
    string endereco;
    std::shared_ptr<livro> colecao_livros[TAMANHO_BIBLIOTECA]; // agregação
    int num_livros;
public:	
    biblioteca(const string &n, const string &e);
    ~biblioteca();

    string get_nome();

    void set_nome(const string &n);

    string get_endereco();

    void set_endereco(const string &e);

    std::shared_ptr<livro> get_livro(int pos);

    void add_livro(std::shared_ptr<livro> l);

    int get_num_livros();

    void print_info();
};

#endif //BIBLIOTECA_H