#ifndef JOGO_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define JOGO_H // Define um novo cabeçalho

// Inclusão dos cabeçalhos
#include "time.h"
#include "juiz.h"

/**
 * @class jogo
 * @brief Representa uma partida de futebol entre dois times.
 *
 * A classe jogo mantém informações sobre os times envolvidos, o juiz, e o resultado da partida.
 * Também possui métodos para registrar o resultado e exibir as informações do jogo.
 */
class jogo {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    time *time_casa; // Ponteiro para o time jogando em casa
    time *time_visitante; // Ponteiro para o time visitante
    juiz *juiz_principal; // Ponteiro para o juiz responsável pela partida
    int gols_time_casa; // Gols marcados pelo time da casa
    int gols_time_visitante; // Gols marcados pelo time visitante
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe jogo.
     * 
     * @param tc Ponteiro para o time da casa.
     * @param tv Ponteiro para o time visitante.
     * @param j Ponteiro para o juiz responsável pela partida.
     */
    jogo(time *tc, time *tv, juiz *j);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~jogo();

    /**
     * @brief Obtém o time da casa.
     * 
     * @return time* Ponteiro para o time da casa.
     */
    time* get_time_casa() const;

    /**
     * @brief Define o time da casa.
     * 
     * @param tc Ponteiro para o time da casa.
     */
    void set_time_casa(time *tc);

    /**
     * @brief Obtém o time visitante.
     * 
     * @return time* Ponteiro para o time visitante.
     */
    time *get_time_visitante() const;

    /**
     * @brief Define o time visitante.
     * 
     * @param tv Ponteiro para o time visitante.
     */
    void set_time_visitante(time *tv);

    /**
     * @brief Obtém o juiz responsável pela partida.
     * 
     * @return juiz* Ponteiro para o juiz principal.
     */
    juiz *get_juiz_principal() const;

    /**
     * @brief Define o juiz responsável pela partida.
     * 
     * @param j Ponteiro para o juiz principal.
     */
    void set_juiz_principal(juiz *j);

    /**
     * @brief Obtém o número de gols marcados pelo time da casa.
     * 
     * @return int Gols marcados pelo time da casa.
     */
    int get_gols_time_casa() const;

    /**
     * @brief Define o número de gols marcados pelo time da casa.
     * 
     * @param g Número de gols marcados pelo time da casa.
     */
    void set_gols_time_casa(int g);

    /**
     * @brief Obtém o número de gols marcados pelo time visitante.
     * 
     * @return int Gols marcados pelo time visitante.
     */
    int get_gols_time_visitante() const;

    /**
     * @brief Define o número de gols marcados pelo time visitante.
     * 
     * @param g Número de gols marcados pelo time visitante.
     */
    void set_gols_time_visitante(int g);

    /**
     * @brief Registra o resultado do jogo.
     * 
     * Atualiza o número de gols marcados por cada time e ajusta a pontuação dos times,
     * com base no resultado da partida.
     * 
     * @param gc Gols marcados pelo time da casa.
     * @param gv Gols marcados pelo time visitante.
     */
    void registrar_resultado(int gc, int gv);

    /**
     * @brief Exibe as informações detalhadas do jogo.
     * 
     * Exibe o nome dos times, o número de gols marcados por cada time e o juiz responsável.
     */
    void exibir_informacoes() const;
};

#endif // Fim da verificação de inclusão JOGO_H