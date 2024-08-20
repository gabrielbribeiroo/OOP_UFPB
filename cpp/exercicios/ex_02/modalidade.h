#ifndef MODALIDADE_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define MODALIDADE_H // Define um novo cabeçalho

#include <string> // Inclui a biblioteca string para usar objetos do tipo string

using std::string;

class modalidade {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome; // Nome da modalidade esportiva
    bool individual; // Modalidade é individual (true) ou coletiva (false)
 
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    // Métodos construtor (aloca memória) e destrutor (desaloca memória)
    modalidade(const string &n, bool i); // Construtor para inicializar os atributos
    ~modalidade(); // Destrutor para liberar recursos e destruir o objeto ao final (quando não é mais chamado)

    // Métodos getters e setters para acessar e modificar os atributos
    string get_modalidade() const; // Retorna o nome da modalidade
    void set_modalidade(const string &n); // Modifica o nome da modalidade

    bool is_individual() const; // Verifica e retorna o tipo da modalidade (individual/coletiva)
    void set_individual(bool i); // Modifica o tipo de modalidade

    void print_info(); // Exibe as informações da modalidade esportiva
};

#endif // Fim da verificação de inclusão MODALIDADE_H