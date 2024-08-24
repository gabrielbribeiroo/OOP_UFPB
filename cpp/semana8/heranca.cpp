#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Animal {
    int idade; // Atributo privado
public:
    // Método construtor inicializando a idade com 0 (caso não seja passado o valor)
    Animal(int i=0): idade(i) {
        cout << "animal(" << idade << ")" << endl;
    } 

    int get_idade() {
        return idade; // Retorna a idade 
    }

    void set_idade(int i) {
        idade = i; // Modifica o valor da idade com o atributo passado como parâmetro
    } 

    // Detalha a informação (idade) do animal
    void print_info() {
        cout << "animal(" << idade << ")" << endl;
    }

    ~Animal() {} // Método destrutor
};

// Herança (a classe Cachorro(classe derivada) é um subtipo/especialização da classe Animal(classe base))
class Cachorro: public Animal {
// Métodos exclusivos da classe Cachorro (classe Animal permance inalterada)
    string latido; // Atributo privado
public:
    // Método construtor
    Cachorro(int i, const string &l): Animal(i), latido(l) {
        // Passa o valor inteiro (inicializando a idade) para o construtor de Animal e a string para o atributo interno
        cout << "cachorro(" << get_idade() << ", " << latido << ")" << endl;
    } 

    string get_latido() {
        return latido; // Retorna o latido
    }

    void set_latido(const string &l) {
        latido = l; // Modifica o latido com o atributo passado como parâmetro
    }

    // Detalha as informações do cachorro (idade e latido)
    void print_info() {
        cout << "cachorro(" << get_idade() << ", " << latido << ")" << endl;
    } 

    ~Cachorro() {} // Método destrutor
};

int main() {
    Cachorro c1(7, "AUAU"); // Objeto c1 da classe Cachorro com idade=7 e latido=AUAU
    Cachorro c2(9, "AWAW"); // Objeto c2 da classe Cachorro com idade=9 e latido=AWAW
    // c1.print_info(); // Exibe as informações do objeto c1
    // c2.print_info(); // Exibe as informações do objeto c2

    cout << endl;
    Animal *pa = &c1; // Ponteiro pa da classe Animal (apenas métodos da classe animal) aponta para o endereço de memória de c1
    pa->set_idade(10); // Modifica a idade para 10
    pa->print_info(); // Exibe as informações após atualizações

    return 0;
}   