#ifndef ATLETA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define ATLETA_H // Define um novo cabeçalho

#include <memory> // Biblioteca dos smart pointers (ponteiros inteligentes)
#include "pais.h" // Inclui o cabeçalho da classe pais
#include "modalidade.h" // Inclui o cabeçalho da classe modalidade

using std::string;

class atleta {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome; // Nome do atleta
    std::unique_ptr<pais> pais; // Ponteiro inteligente para o objeto da classe pais (composição)
    std::unique_ptr<modalidade> modalidade; // Ponteiro inteligente para o objeto da classe modalidade (agregação)

public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    // Métodos construtor (aloca memória) e destrutor (desaloca memória)
    atleta(const string &n, std::unique_ptr<pais> p, std::unique_ptr<modalidade> m); // Construtor para inicializar os atributos
    ~atleta(); // Destrutor para liberar recursos e destruir o objeto ao final (quando não é mais chamado)
    
    // Métodos getters e setters para acessar e modificar os atributos
    string get_nome() const; // Retorna o nome do atleta
    void set_nome(const string &n); // Modifica o nome do atleta

    pais *get_pais() const; // Retorna o nome do país do atleta
    void set_pais(std::unique_ptr<pais> p); // Modifica o nome do país do atleta

    modalidade *get_modalidade() const; // Retorna o nome da modalidade praticada pelo atleta
    void set_modalidade(std::unique_ptr<modalidade> m); // Modifica o nome da modalidade praticada pelo atleta

    void print_info(); // Exibe as informações do atleta, incluindo seu país e modalidade praticada
};

#endif // Fim da verificação de inclusão ATLETA_H