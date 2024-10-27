#ifndef EMPRESA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define EMPRESA_H // Define um novo cabeçalho

#include <string>

using std::string;

/**
 * @class empresa
 * @brief Representa uma empresa locatária.
 *
 * A classe empresa mantém informações sobre o nome e a idade da empresa. 
 * Também possui métodos para tratamento de exceções, e sobrecarrega o operador < para comparar 
 * a idade de duas empresas.
 */
class empresa {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    string nome_da_empresa; // Nome da empresa
    int idade_da_empresa; // Idade da empresa
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor que inicializa os atributos da classe empresa e lança uma exceção para idade negativa.
     * 
     * @param nome Nome da empresa. 
     * @param idade Idade da empresa.
     */
    empresa(const string &nome, int idade);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~empresa();
    
    /**
     * @brief Obtém o nome da empresa.
     * 
     * @return string O nome da empresa.
     */
    string get_nome() const;
    
    /**
     * @brief Define o nome da empresa.
     * 
     * @param nome O nome a ser definido para a empresa.
     */
    void set_nome(const string &nome);

    /**
     * @brief Obtém a idade da empresa.
     * 
     * @return int A idade da empresa.
     */
    int get_idade() const;

    /**
     * @brief Define a idade da empresa e lança uma exceção caso a idade lançada for negativa.
     * 
     * @param idade A idade a ser definida para a empresa.
     */
    void set_idade(int idade);

    /**
     * @brief Sobrecarga do operador < para comparar a idade de duas empresas (empresas mais antigas vêm primeiro).
     * 
     * @param outro Referência para outra empresa a ser comparada.
     * 
     * @return bool Comparação de qual empresa é mais nova.
     */
    bool operator<(const empresa &outro) const;
};

#endif // Fim da verificação de inclusão EMPRESA_H