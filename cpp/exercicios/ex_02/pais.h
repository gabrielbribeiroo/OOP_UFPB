#ifndef PAIS_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define PAIS_H // Define um novo cabeçalho

#include <string> // Inclui a biblioteca string para usar objetos do tipo string

using std::string;

class Pais {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome; // Nome do país
    string continente; // Continente do país

public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    // Métodos construtor (aloca memória) e destrutor (desaloca memória)
    Pais(const string &nome, const string &continente); // Construtor para inicializar os atributos
    ~Pais(); // Destrutor para liberar recursos e destruir o objeto ao final (quando não é mais chamado)

    // Métodos getters e setters para acessar e modificar os atributos
    string get_pais() const; // Retorna o nome do país
    void set_pais(const string &nome); // Modifica o nome do país

    string get_continente() const; // Retorna o nome do continente
    void set_continente(const string &continente); // Modifica o nome do continente
    
    void print_info(); // Exibe as informações do país
};

#endif // Fim da verificação de inclusão PAIS_H
