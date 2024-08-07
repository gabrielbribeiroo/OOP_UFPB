/*
Classe livro:
    - Atributos: titulo, ano de publicação e autor (composição)
    - Métodos: construtor, destrutor, gets e sets, print_info
Classe autor:
    - Atributos: nome, data de nascimento, nacionalidade
    - Métodos: construtor, destrutor, gets e sets, print_info
Classe biblioteca:
    - Atributos: nome, endereço, coleção de livros (agregação)
    - Métodos: construtor, destrutor, gets e sets, print_info
*/

#include <iostream>
#include <string>
#include <memory>

#define TAMANHO_BIBLIOTECA 100

using std::cout;
using std::endl;
using std::string;

class autor {
    string nome;
    string data_nascimento;
    string nacionalidade;
public:
    autor(const string &n, const string &d, const string &na) : nome(n), data_nascimento(d), nacionalidade(na) {
        cout << "Autor: " << nome << " criado!" << endl;
    }

    ~autor() {
        cout << "Autor: " << nome << " destruido!" << endl;
    }

    string get_nome() {
        return nome;
    }

    void set_nome(const string &n) {
        nome = n;
    }

    string get_data_nascimento() {
        return data_nascimento;
    }

    void set_data_nascimento(const string &d) {
        data_nascimento = d;
    }

    string get_nacionalidade() {
        return nacionalidade;
    }

    void set_nacionalidade(const string &na) {
        nacionalidade =  na;
    }

    void print_info() {
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << data_nascimento << endl;
        cout << "Nacionalidade: " << nacionalidade << endl;
    }
};

class livro {
    string titulo;
    int ano;
    std::shared_ptr<autor> autor_livro; // agregação
public:
    livro(const string &t, int a, std::shared_ptr<autor> au): titulo(t), ano(a), autor_livro(au) {
        cout << "Livro: " << titulo << " criado!" << endl;
    }

    ~livro() {
        cout << "Livro: " << titulo << " destruido!" << endl;
    }

    string get_titulo() {
        return titulo;
    }

    void set_titulo(const string &t) {
        titulo = t;
    }

    int get_ano() {
        return ano;
    }

    void set_ano(int a) {
        ano = a;
    }

    std::shared_ptr<autor> get_autor() {
        return autor_livro;
    }

    void set_autor(std::shared_ptr<autor> au) {
        autor_livro = au;
    }

    void print_info() {
        cout << "Titulo: " << titulo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Autor: " << endl;
        autor_livro->print_info();
    }
};

class biblioteca {
    string nome;
    string endereco;
    std::shared_ptr<livro> colecao_livros[TAMANHO_BIBLIOTECA]; // agregacao
    int num_livros;
public:
    biblioteca(const string &n, const string &e) : nome(n), endereco(e) {
        num_livros = 0;
        cout << "Biblioteca: " << nome << " criada!" << endl;
    }

    ~biblioteca() {
        cout << "Biblioteca: " << nome << " destruida!" << endl;
    }

    string get_nome() {
        return nome;
    }

    void set_nome(const string &n) {
        nome = n;
    }

    string get_endereco() {
        return endereco;
    }

    void set_endereco(const string &e) {
        endereco = e;
    }

    std::shared_ptr<livro> get_livro(int pos) {
        return colecao_livros[pos];
    }

    void add_livro(std::shared_ptr<livro> l) {
        if (num_livros < TAMANHO_BIBLIOTECA) {
            colecao_livros[num_livros] = l;
            num_livros++;
        } 
        else {
            cout << "Biblioteca cheia!" << endl;
        }
    }

    int get_num_livros() {
        return num_livros;
    }    

    void print_info() {
        cout << "Nome: " << nome << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "Colecao de livros: " << endl;
        for (int i=0; i<num_livros; i++) {
            colecao_livros[i]->print_info();
        }
    }
};

int main(void) {
    // autor a1("Machado de Assis", "21/06/1839", "Brasileiro");
    string nome_autor = "Machado de Assis";
    string data_nascimento = "21/06/1839";
    string nacionalidade = "Brasileiro";
    autor a1(nome_autor, data_nascimento, nacionalidade);

    nome_autor = "George R. R. Martin";
    data_nascimento = "20/09/1948";
    nacionalidade = "Americano";
    autor a2(nome_autor, data_nascimento, nacionalidade);

    autor a3("J. K. Rowling", "31/07/1965", "Britanico");
    
    std::shared_ptr<autor> pa1 = std::make_shared<autor>(a1);
    livro l1("Dom Casmurro", 1899, pa1);
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

    l1.print_info();

    //b1.print_info();

    /*
    // Fazer modificação ser refletida no objeto l1
    a1.set_nome("Machado de Assis Junior");
    l1.print_info();
    */
   
    return 0;
}