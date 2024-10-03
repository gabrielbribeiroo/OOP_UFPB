#ifndef TECNICO_JOGADOR_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define TECNICO_JOGADOR_H // Define um novo cabeçalho

/**
 * @file tecnico_jogador.h
 * @brief Este arquivo contém a implementação das classes tecnico e jogador.
 * 
 * As classes tecnico e jogador demonstram o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

class pessoa {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
};

/**
 * @class tecnico
 * @brief Classe que representa um técnico de futebol.
 *
 * A classe tecnico mantém informações sobre -----------------
 */
class tecnico {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)

public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    // Métodos construtor (aloca memória) e destrutor (desaloca memória)
    tecnico(); // Construtor para inicializar os atributos
    ~tecnico(); // Destrutor para liberar recursos e destruir o objeto ao final (quando não é mais chamado)

    // Métodos getters e setters para acessar e modificar os atributos
    tecnico get_tecnico() const; // Retorna o técnico 
    void set_tecnico(const tecnico &t); // Modifica o técnico

    void print_info() const; // Exibe as informações do técnico
};

/**
 * @class jogador
 * @brief Classe que representa um jogador de futebol.
 *
 * A classe jogador mantém informações sobre a posição, gols marcados e salário do jogador, 
 * além de permitir o cálculo do salário total.
 */
class jogador {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string posicao; // Posição do jogador
    int gols_marcados; // Número de gols marcados pelo jogador
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor padrão que inicializa um jogador com uma posição e número de gols.
     *
     * @param posicao A posição do jogador (goleiro, zagueiro, etc.).
     * @param gols Número de gols marcados pelo jogador.
     */
    jogador(const string &posicao, int gols);
    ~jogador(); // Destrutor para liberar recursos e destruir o objeto ao final (quando não é mais chamado)

    // Métodos getters e setters para acessar e modificar os atributos
    string get_posicao() const; // Retorna a posição do atleta
    void set_posicao(const string &p); // Modifica a posição do atleta
    int get_gols_marcados() const; // Retorna o número de gols marcados
    void set_gols_marcados(int g); // Modifica o número de gols marcados

    /**
     * @brief Adiciona mais gols ao número já inicializado.
     *
     * @param gols Número de gols marcados pelo jogador.
     */
    void adicionar_gols(int gols);

    /**
     * @brief Calcula o salário total do jogador com base no número de gols.
     *
     * @return double salário total calculado.
     */
    double calcular_salario() const;

    void print_info() const; // Exibe as informações do jogador, incluindo posição, gols e salário
};

#endif // Fim da verificação de inclusão TECNICO_JOGADOR_H