#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <memory>
#include "autor.h"

using std::string;

class livro {
    string titulo;
    int ano;
    std::shared_ptr<autor> autor_livro; // agregação
public:
    livro(const string &t, int a, std::shared_ptr<autor> au);
    ~livro();

    string get_titulo();

    void set_titulo(const string &t);

    int get_ano();

    void set_ano(int a);

    std::shared_ptr<autor> get_autor();

    void set_autor(std::shared_ptr<autor> au);

    void print_info();
};

#endif //LIVRO_H