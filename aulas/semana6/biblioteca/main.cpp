#include <iostream>
#include <string>
#include <memory>
#include "autor.h"
#include "livro.h"
#include "biblioteca.h"

using std::string;
using std::cout;
using std::endl;

int main(void) {
    string nome_autor = "Machado de Assis";
    string data_nascimento = "21/06/1839";
    string nacionalidade = "Brasileiro";
    // autor a1(nome_autor, data_nascimento, nacionalidade);
    auto a1 = std::make_shared<autor>(nome_autor, data_nascimento, nacionalidade);

    nome_autor = "George R. R. Martin";
    data_nascimento = "20/09/1948";
    nacionalidade = "Americano";
    // autor a2(nome_autor, data_nascimento, nacionalidade);
    auto a2 = std::make_shared<autor>(nome_autor, data_nascimento, nacionalidade);
    // autor a3("J. K. Rowling", "31/07/1965", "Britanico");
    auto a3 = std::make_shared<autor>("J. K. Rowling", "31/07/1965", "Britanico");

    // auto a1 = std::make_shared<autor>("Machado de Assis", "21/06/1839", "Brasileiro");

    auto l1 = std::make_shared<livro>("Dom Casmurro", 1899, a1);
    auto l2 = std::make_shared<livro>("Memorias Postumas de Bras Cubas", 1881, a1);
    auto l3 = std::make_shared<livro>("A Game of Thrones", 1996, a2);
    auto l4 = std::make_shared<livro>("A Clash of Kings", 1998, a2);
    auto l5 = std::make_shared<livro>("Harry Potter and the Philosopher's Stone", 1997, a3);
    auto l6 = std::make_shared<livro>("Harry Potter and the Chamber of Secrets", 1998, a3);

    biblioteca b1("Biblioteca Central", "Rua da Biblioteca, 1000");

    b1.add_livro(l1);
    b1.add_livro(l2);
    b1.add_livro(l3);
    b1.add_livro(l4);
    b1.add_livro(l5);
    b1.add_livro(l6);

    b1.print_info();

    /*
    //TESTANDO SHARED POINTERS
    l1->print_info();
    l2->print_info();
    a1->set_nome("Machado de Assis Junior");
    l1->print_info();
    l2->print_info();
    */
   
    return 0;
}