#ifndef JOGADOR_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define JOGADOR_H // Define um novo cabeçalho

/**
 * @file jogador.h
 * @brief Este arquivo contém o cabeçalho da classe jogador.
 * 
 * A classe jogador demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "membro_clube.h" // Inclui o cabeçalho da classe base

/**
 * @class jogador
 * @brief Classe que representa um jogador de futebol que herda de membro_clube.
 *
 * A classe jogador contém informações sobre a posição do jogador e o número
 * de gols marcados, além de funcionalidades para calcular o salário e 
 * comparar jogadores pelo número de gols.
 */
class jogador : public membro_clube {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string posicao; // Posição do jogador (goleiro, zagueiro, meio-campo, atacante)
    int gols_marcados; // Número total de gols marcados pelo jogador
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe jogador.
     * 
     * @param nome Nome do jogador.
     * @param idade Idade do jogador.
     * @param salario Salário base do jogador.
     * @param posicao Posição que o jogador ocupa no campo.
     * @param gols_marcados Total de gols marcados pelo jogador.
     */
    jogador(const string &n, int i, double s, const string &p, int g);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~jogador(); 

    /**
     * @brief Obtém a posição do jogador.
     * 
     * @return Posição do jogador no campo (goleiro, zagueiro, meio-campo, atacante).
     */
    string get_posicao() const;

    /**
     * @brief Define a posição do jogador.
     * 
     * @param p Posição que o jogador irá ocupar no campo.
     */
    void set_posicao(const string &p);

    /**
     * @brief Obtém o número de gols marcados pelo jogador.
     * 
     * @return Número total de gols marcados pelo jogador.
     */
    int get_gols_marcados() const;

    /**
     * @brief Define o número de gols marcados pelo jogador.
     * 
     * @param g Total de gols marcados a ser definido.
     */
    void set_gols_marcados(int g);

    /**
     * @brief Calcula o salário do jogador.
     * 
     * O salário é calculado como o salário base mais um bônus de 100 para cada gol marcado.
     * 
     * @return Salário total do jogador, incluindo o bônus por gols.
     */
    double calcular_salario() const override;

    /**
     * @brief Sobrecarga do operador < para comparar jogadores pelo número de gols marcados.
     * 
     * @param outro Outro jogador a ser comparado.
     * @return true se o jogador atual tiver menos gols marcados que o outro jogador, false caso contrário.
     */
    bool operator<(const jogador &outro) const;
};

#endif // Fim da verificação de inclusão JOGADOR_H