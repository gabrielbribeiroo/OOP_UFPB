#ifndef PESSOA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define PESSOA_H // Define um novo cabeçalho

/**
 * @file pessoa.h
 * @brief Este arquivo contém o cabeçalho da classe pessoa.
 * 
 * A classe pessoa demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
 * @class pessoa
 * @brief Classe que representa uma pessoa.
 *
 * A classe pessoa mantém informações sobre o nome e a idade da pessoa, 
 * além de permitir a contagem de objetos criados.
 */
class pessoa {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome; // Nome completo da pessoa
    int idade; // Idade da pessoa
    static int contador; // Variável estática para contar o número de pessoas
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor padrão que inicializa uma pessoa com um nome e uma idade.
     *
     * @param nome O nome da pessoa.
     * @param idade A idade da pessoa.
     * @param contador O número de pessoas.
     */
    pessoa(const string &n, int i);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~pessoa(); 

    /**
     * @brief Retorna o nome da pessoa.
     *
     * O método `get_nome` é usado para acessar o atributo privado `nome` de uma instância
     * da classe `pessoa`.
     *
     * @return string O nome completo da pessoa.
     */
    string get_nome() const;

    /**
     * @brief Modifica o nome da pessoa.
     *
     * O método `set_nome` é usado para atribuir um novo valor ao atributo privado `nome`.
     * Ele aceita uma string constante, passada por referência, para evitar cópia desnecessária de dados.
     *
     * @param n O novo nome completo da pessoa.
     */
    void set_nome(const string &n);

    /**
     * @brief Retorna a idade da pessoa.
     *
     * O método `get_idade` é usado para acessar o atributo privado `idade` de uma instância
     * da classe `pessoa`.
     *
     * @return int A idade atual da pessoa.
     */
    int get_idade() const;

    /**
     * @brief Modifica a idade da pessoa.
     *
     * O método `set_idade` é usado para atribuir um novo valor ao atributo privado `idade`.
     * Ele aceita um valor inteiro que representa a nova idade da pessoa.
     *
     * @param i A nova idade da pessoa.
     */
    void set_idade(int i);

    /**
     * @brief Retorna o número total de instâncias da classe pessoa.
     *
     * O método estático `get_contador` é usado para obter o valor do atributo
     * estático `contador`, que armazena a quantidade de objetos da classe `pessoa`
     * (ou suas classes derivadas) criados até o momento. 
     * Esse valor é atualizado automaticamente pelo construtor e destrutor da classe.
     *
     * @return int O número total de pessoas instanciadas.
     */
    static int get_contador();

    /**
     * @brief Método virtual puro para exibir as informações da pessoa.
     *
     * O método `exibir_informacoes` é um método virtual puro, que deve ser implementado
     * em qualquer classe derivada de `pessoa`. Ele é utilizado para exibir as informações
     * detalhadas da pessoa, como nome, idade, e possivelmente outros dados de subclasses.
     *
     * Como é um método virtual puro, a classe `pessoa` é abstrata e não pode ser instanciada.
     *
     * @note Este método deve ser sobrescrito em todas as classes derivadas.
     */
    virtual void exibir_informacoes() const = 0;

    /**
     * @brief Sobrecarga do operador de igualdade para comparar duas pessoas.
     *
     * O operador `==` é sobrecarregado para comparar duas instâncias da classe `pessoa`.
     * A comparação é feita com base nos atributos `nome` e `idade`. Duas pessoas são 
     * consideradas iguais se tiverem o mesmo nome e a mesma idade.
     *
     * @param outro Referência para outra instância de `pessoa` que será comparada.
     * @return true Se o nome e a idade das duas pessoas forem iguais.
     * @return false Caso contrário.
     */
    bool operator==(const pessoa &outro) const;
};

#endif // Fim da verificação de inclusão PESSOA_H