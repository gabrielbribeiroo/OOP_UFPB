#ifndef MEDALHA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define MEDALHA_H // Define um novo cabeçalho

#include "atleta.h" // Inclui o cabeçalho da classe atleta

class medalha {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string tipo; // Tipo de medalha (ouro, prata ou bronze)
    int ano; // Ano de conquista
    std::unique_ptr<atleta> a; // Ponteiro inteligente para o objeto da classe atleta (composição)
    std::unique_ptr<modalidade> m; // Ponteiro inteligente para o objeto da classe modalidade (composição)

public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    // Métodos construtor (aloca memória) e destrutor (desaloca memória)
    medalha(const string &t, int ano, std::unique_ptr<atleta> a, std::unique_ptr<modalidade> m); // Construtor para inicializar os atributos
    ~medalha(); // Destrutor para liberar recursos e destruir o objeto ao final (quando não é mais chamado)

    // Métodos getters e setters para acessar e modificar os atributos
    string get_tipo() const; // Retorna o tipo da medalha (ouro/prata/bronze) conquistada
    void set_tipo(const string &t); // Modifica o tipo de medalha (ouro/prata/bronze) conquistada

    int get_ano() const; // Retorna o ano de conquista da medalha
    void set_ano(int ano); // Modifica o ano de conquista da medalha

    atleta *get_atleta() const; // Retorna as informações do atleta que conquistou a medalha (através de smart pointer)
    void set_atleta(std::unique_ptr<atleta> a); // Modifica as informações do atleta que conquistou a medalha (através de smart pointer)

    modalidade *get_modalidade() const; // Retorna as informações da modalidade esportiva, na qual foi medalhista (através de smart pointer)
    void set_modalidade(std::unique_ptr<modalidade> m); // Modifica as informações da modalidade esportiva, na qual foi medalhista (através de smart pointer)

    void print_info(); // Exibe as informações da medalha conquistada, incluindo o atleta e a modalidade esportiva
};

#endif // Fim da verificação de inclusão MEDALHA_H