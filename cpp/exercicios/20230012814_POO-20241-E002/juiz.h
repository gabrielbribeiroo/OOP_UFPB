#ifndef JUIZ_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define JUIZ_H // Define um novo cabeçalho

/**
 * @file juiz.h
 * @brief Este arquivo contém o cabeçalho da classe juiz.
 * 
 * A classe juiz demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "pessoa.h" // // Inclui o cabeçalho da classe base

/**
 * @class juiz
 * @brief Representa um juiz de futebol que herda de pessoa.
 *
 * A classe juiz mantém informações sobre o número de partidas arbitradas
 * e implementa funcionalidades específicas para incrementar e exibir essas informações.
 */

class juiz : public pessoa {
private:
    int partidas_arbitradas; ///< Número total de partidas arbitradas pelo juiz

public:
    /**
     * @brief Construtor que inicializa os atributos da classe juiz.
     * 
     * @param n Nome do juiz.
     * @param i Idade do juiz.
     * @param p Número de partidas arbitradas pelo juiz.
     */
    juiz(const string &n, int i, int p);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~juiz();

    /**
     * @brief Obtém o número de partidas arbitradas pelo juiz.
     * 
     * @return int O número total de partidas arbitradas.
     */
    int get_partidas_arbitradas() const;

    /**
     * @brief Define o número de partidas arbitradas pelo juiz.
     * 
     * @param p O número de partidas a ser definido.
     */
    void set_partidas_arbitradas(int p);

    /**
     * @brief Incrementa o número de partidas arbitradas pelo juiz.
     * 
     * Este método aumenta em 1 o número de partidas arbitradas.
     */
    void incrementar_partidas_arbitradas();

    /**
     * @brief Exibe as informações detalhadas do juiz.
     * 
     * Implementação do método virtual puro da classe base pessoa para exibir
     * o número de partidas arbitradas.
     */
    void exibir_informacoes() const override;
};

#endif // Fim da verificação de inclusão JUIZ_H