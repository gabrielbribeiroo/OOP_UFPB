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
    autor a1(nome_autor, data_nascimento, nacionalidade);

    nome_autor = "George R. R. Martin";
    data_nascimento = "20/09/1948";
    nacionalidade = "Americano";
    autor a2(nome_autor, data_nascimento, nacionalidade);

    autor a3("J. K. Rowling", "31/07/1965", "Britanico");

    //auto a1 = std::make_shared<autor>("Machado de Assis", "21/06/1839", "Brasileiro");

    livro l1("Dom Casmurro", 1899, std::make_shared<autor>(a1));
    livro l2("Memorias Postumas de Bras Cubas", 1881, std::make_shared<autor>(a1));
    livro l3("A Game of Thrones", 1996, std::make_shared<autor>(a2));
    livro l4("A Clash of Kings", 1998, std::make_shared<autor>(a2));
    livro l5("Harry Potter and the Philosopher's Stone", 1997, std::make_shared<autor>(a3));
    livro l6("Harry Potter and the Chamber of Secrets", 1998, std::make_shared<autor>(a3));

    biblioteca b1("Biblioteca Central", "Rua da Biblioteca, 1000");
    b1.add_livro(std::make_shared<livro>(l1));
    b1.add_livro(std::make_shared<livro>(l2));
    b1.add_livro(std::make_shared<livro>(l3));
    b1.add_livro(std::make_shared<livro>(l4));
    b1.add_livro(std::make_shared<livro>(l5));
    b1.add_livro(std::make_shared<livro>(l6));

    b1.print_info();

    /*
    l1.print_info();
    //Fazer modificacao ser refletida no objeto l1
    a1.set_nome("Machado de Assis Junior");
    l1.print_info();
    */
   
    return 0;
}