#ifndef TIME_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define TIME_H // Define um novo cabeçalho

/**
 * @file time.h
 * @brief Este arquivo contém o cabeçalho da classe time.
 * 
 * A classe time demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include <vector>

using std::vector;

// Inclui os cabeçalhos das classes base
#include "tecnico.h"
#include "jogador.h"

/**
 * @class time
 * @brief Representa um time de futebol.
 *
 * A classe time mantém informações sobre o nome do time, o técnico, os jogadores
 * e a pontuação total do time. Também possui métodos para adicionar jogadores, 
 * registrar resultados e exibir informações.
 */
class time {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome; // Nome do time
    tecnico *tecnico_ptr; // Ponteiro para o técnico do time
    vector<jogador> jogadores; // Lista de jogadores do time
    int pontuacao; // Pontuação total do time
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe time.
     * 
     * @param n Nome do time.
     * @param t Ponteiro para o técnico do time.
     * @param p Pontuação inicial do time.
     */
    time(const string &n, tecnico *t, int p = 0);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~time();

    /**
     * @brief Obtém o nome do time.
     * 
     * @return string O nome do time.
     */
    string get_nome() const;

    /**
     * @brief Define o nome do time.
     * 
     * @param n Nome a ser definido para o time.
     */
    void set_nome(const string &n);

    /**
     * @brief Obtém o técnico do time.
     * 
     * @return tecnico* Ponteiro para o técnico do time.
     */
    tecnico* get_tecnico() const;

    /**
     * @brief Define o técnico do time.
     * 
     * @param t Ponteiro para o técnico a ser definido.
     */
    void set_tecnico(tecnico *t);

    /**
     * @brief Obtém a pontuação do time.
     * 
     * @return int A pontuação total do time.
     */
    int get_pontuacao() const;

    /**
     * @brief Define a pontuação do time.
     * 
     * @param p Nova pontuação a ser definida.
     */
    void set_pontuacao(int p);

    /**
     * @brief Adiciona um jogador ao time.
     * 
     * @param j Referência para um objeto Jogador a ser adicionado.
     */
    void adicionar_jogador(const jogador &j);

    /**
     * @brief Registra o resultado de uma partida e atualiza a pontuação do time.
     * 
     * @param r Resultado da partida ('V' para vitória, 'E' para empate, 'D' para derrota).
     */
    void registrar_resultado(char r);

    /**
     * @brief Exibe as informações completas do time.
     * 
     * Inclui o nome do time, o técnico, a lista de jogadores e a pontuação.
     */
    void exibir_informacoes() const;

    /**
     * @brief Sobrecarga do operador < para comparar times pela pontuação total.
     * 
     * @param outro Outro objeto time a ser comparado.
     * @return true Se o time atual tiver menos pontos que o outro time.
     * @return false Caso contrário.
     */
    bool operator<(const time &outro) const;
};

#endif // Fim da verificação de inclusão TIME_H