#ifndef TECNICO_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define TECNICO_H // Define um novo cabeçalho

/**
 * @file tecnico.h
 * @brief Este arquivo contém o cabeçalho da classe tecnico.
 * 
 * A classe tecnico demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "membro_clube.h" // Inclui o cabeçalho da classe base

/**
 * @class tecnico
 * @brief Representa um técnico de futebol que herda de membro_clube.
 *
 * A classe tecnico contém informações sobre a experiência do técnico em anos
 * e implementa a funcionalidade para calcular o salário, com base nos anos de experiência.
 */
class tecnico : public membro_clube {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    int experiencia; // Anos de experiência como técnico
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe tecnico.
     * 
     * @param nome Nome do técnico.
     * @param idade Idade do técnico.
     * @param salario Salário base do técnico.
     * @param experiencia Anos de experiência como técnico.
     */
    tecnico(const string &n, int i, double s, int e);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~tecnico();

    /**
     * @brief Obtém os anos de experiência do técnico.
     * 
     * @return int O número de anos de experiência.
     */
    int get_experiencia() const;

    /**
     * @brief Define os anos de experiência do técnico.
     * 
     * @param experiencia Anos de experiência a serem definidos.
     */
    void set_experiencia(int experiencia);

    /**
     * @brief Calcula o salário do técnico.
     * 
     * O salário é calculado como o salário base mais um bônus de 200 por cada ano de experiência.
     * 
     * @return double O salário total do técnico.
     */
    double calcular_salario() const override;

    /**
     * @brief Exibe as informações detalhadas do técnico.
     * 
     * Implementa o método virtual puro da classe base pessoa.
     */
    void exibir_informacoes() const override;
};

#endif // Fim da verificação de inclusão TECNICO_H
