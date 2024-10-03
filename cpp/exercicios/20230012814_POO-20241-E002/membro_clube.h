#ifndef MEMBRO_CLUBE_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define MEMBRO_CLUBE_H // Define um novo cabeçalho

/**
 * @file membro_clube.h
 * @brief Este arquivo contém o cabeçalho da classe membro_clube.
 * 
 * A classe membro_clube demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "pessoa.h" // Inclui o cabeçalho da classe base

using std::ostream;

/**
 * @class membro_clube
 * @brief Classe que representa um membro do clube.
 *
 * A classe membro_clube mantém informações sobre o nome e a idade da pessoa, 
 * além do salário do membro.
 */
class membro_clube {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    double salario; // Salario do membro do clube
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor padrão que inicializa um membro com um nome, uma idade e um salário.
     *
     * @param nome O nome do membro.
     * @param idade A idade do membro.
     * @param salario O valor do salário do membro.
     */
    membro_clube(const string &n, int i, double s);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~membro_clube(); 

    /**
     * @brief Retorna o salário do membro.
     *
     * O método `get_salario` é usado para acessar o atributo privado `salario` de uma instância
     * da classe `membro_clube`.
     *
     * @return double O salário do membro.
     */
    double get_salario() const;

    /**
     * @brief Modifica o salário do membro.
     *
     * O método `set_salario` é usado para atribuir um novo valor ao atributo privado `salario`.
     * Ele aceita um valor double.
     *
     * @param s O novo salário do membro.
     */
    void set_salario(double s);

    /**
     * @brief Método virtual puro para calcular o salário do membro do clube.
     *
     * O método `calcular_salario` é um método virtual puro, que deve ser implementado
     * em qualquer classe derivada de `membro_clube`.      *
     * Como é um método virtual puro, a classe `membro_clube` é abstrata e não pode ser instanciada.
     *
     * @note Este método deve ser sobrescrito em todas as classes derivadas.
     */
    virtual double calcular_salario() = 0;

    /**
     * @brief Sobrecarga do operador de saída para exibir informações de um membro do clube.
     *
     * Este operador permite que um objeto da classe `membro_clube` seja enviado para um fluxo de saída, 
     * como `cout`. Ele formata a saída incluindo o nome, a idade e o salário do membro.
     *
     * @param os O fluxo de saída onde as informações do membro serão enviadas.
     * @param membro A referência constante para o objeto `membro_clube` cujas informações serão exibidas.
     * @return ostream& Uma referência ao fluxo de saída, permitindo o encadeamento de operações.
     */
    friend ostream &operator<<(ostream &os, const membro_clube &membro);
};

#endif // Fim da verificação de inclusão MEMBRO_CLUBE_H