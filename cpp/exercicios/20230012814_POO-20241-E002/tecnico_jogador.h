#ifndef TECNICO_JOGADOR_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define TECNICO_JOGADOR_H // Define um novo cabeçalho

/**
 * @file tecnico_jogador.h
 * @brief Este arquivo contém o cabeçalho da classe tecnico_jogador.
 * 
 * A classe tecnico_jogador demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

// Inclui os cabeçalhos das classes base
#include "jogador.h"
#include "tecnico.h"

/**
 * @class tecnico_jogador
 * @brief Representa um técnico-jogador com herança múltipla de jogador e técnico.
 *
 * A classe tecnico_jogador combina as funções de um jogador e um técnico, com um bônus adicional
 * por desempenhar ambos os papéis simultaneamente.
 */
class tecnico_jogador : public jogador, public tecnico {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    double bonus_duplo_papel; // Bônus por atuar como técnico e jogador ao mesmo tempo
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe tecnico_jogador.
     * 
     * @param nome Nome do técnico-jogador.
     * @param idade Idade do técnico-jogador.
     * @param salario Salário base do técnico-jogador.
     * @param posicao Posição do técnico-jogador no campo.
     * @param gols_marcados Número de gols marcados pelo técnico-jogador.
     * @param experiencia Anos de experiência como técnico.
     * @param bonus_duplo_papel Bônus adicional por atuar como técnico e jogador ao mesmo tempo.
     */
    tecnico_jogador(const string &n, int i, double s, const string &p, int g, int e, double b); 

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~tecnico_jogador();

    /**
     * @brief Obtém o valor do bônus por atuar como técnico e jogador.
     * 
     * @return double O valor do bônus.
     */
    double get_bonus_duplo_papel() const;

    /**
     * @brief Define o valor do bônus por atuar como técnico e jogador.
     * 
     * @param b O novo valor do bônus.
     */
    void set_bonus_duplo_papel(double b);

    /**
     * @brief Calcula o salário total do técnico-jogador.
     * 
     * O salário é calculado como a soma do salário de jogador, técnico e o bônus por duplo papel.
     * 
     * @return double O salário total do técnico-jogador.
     */
    double calcular_salario() const override;

    /**
     * @brief Exibe as informações detalhadas do técnico-jogador.
     * 
     * Implementa o método virtual puro da classe base pessoa.
     */
    void exibir_informacoes() const override;

    /**
     * @brief Sobrecarga do operador de saída para exibir informações detalhadas do técnico-jogador.
     *
     * Este operador permite exibir informações completas de um técnico-jogador, incluindo nome, idade, salário, 
     * posição, número de gols, anos de experiência e o bônus por duplo papel.
     * 
     * @param os O fluxo de saída onde as informações do técnico-jogador serão enviadas.
     * @param t A referência constante para o objeto TecnicoJogador.
     * 
     * @return ostream& Uma referência ao fluxo de saída, permitindo o encadeamento de operações.
     */
    friend ostream &operator<<(ostream &os, const tecnico_jogador &t);
};

#endif // Fim da verificação de inclusão TECNICO_JOGADOR_H