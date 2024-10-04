#ifndef CAMPEONATO_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define CAMPEONATO_H // Define um novo cabeçalho

#include <algorithm>

using std::sort;

#include "time.h"
#include "jogo.h"

/**
 * @class campeonato
 * @brief Representa um campeonato de futebol.
 *
 * A classe campeonato mantém informações sobre o nome do campeonato, a lista de times
 * e a lista de jogos. Também possui métodos para adicionar times e jogos, e para exibir
 * a classificação dos times.
 */
class campeonato {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome_campeonato; // Nome do campeonato
    vector<time*> times; // Lista de times no campeonato
    vector<jogo> jogos; // Lista de jogos no campeonato
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe campeonato.
     * 
     * @param n Nome do campeonato.
     */
    campeonato(const string &n);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~campeonato();

    /**
     * @brief Obtém o nome do campeonato.
     * 
     * @return string O nome do campeonato.
     */
    string get_nome_campeonato() const;

    /**
     * @brief Define o nome do campeonato.
     * 
     * @param n O nome a ser definido para o campeonato.
     */
    void set_nome_campeonato(const string &n);

    /**
     * @brief Adiciona um time ao campeonato.
     * 
     * Adiciona um time à lista de times participantes do campeonato.
     * 
     * @param t Referência para o objeto time a ser adicionado.
     */
    void adicionar_time(time &t); // Aceita o objeto time por referência

    /**
     * @brief Adiciona um jogo ao campeonato.
     * 
     * Adiciona um jogo à lista de jogos do campeonato.
     * 
     * @param j Referência para o objeto jogo a ser adicionado.
     */
    void adicionar_jogo(const jogo &j);

    /**
     * @brief Exibe a classificação dos times no campeonato.
     * 
     * Ordena os times pela pontuação e exibe a tabela de classificação.
     */
    void exibir_classificacao() const;
};


#endif // Fim da verificação de inclusão CAMPEONATO_H