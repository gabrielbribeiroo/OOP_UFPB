#ifndef SALA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define SALA_H // Define um novo cabeçalho

#include <vector>
#include "empresa.h"

using std::vector;

/**
 * @class sala
 * @brief Classe abstrata que representa uma sala comercial.
 *
 * A classe sala mantém informações sobre o número e andar da sala, além da lista de empresas locatárias. 
 * Também possui método virtual para calcular preço, ordenar empresas e sobrecargas dos operadores <, + e -.
 */
class sala {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    int numero_da_sala; // Número da sala
    int andar; // Número do andar que se localiza a sala
    vector<empresa> lista_de_empresas_locatarias; // Vetor com as empresas locatárias
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor da classe abstrata sala.
     * 
     * @param numero Número da sala. 
     * @param andar Andar da sala.
     */
    sala(int numero, int andar);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~sala();

    /**
     * @brief Obtém o número da sala.
     * 
     * @return int O número da sala.
     */
    int get_numero() const;

    /**
     * @brief Define o número da sala.
     * 
     * @param numero O número a ser definido para a sala.
     */
    void set_numero(int numero);

    /**
     * @brief Obtém o andar da sala.
     * 
     * @return int O número do andar da sala.
     */
    int get_andar() const;

    /**
     * @brief Define o andar da sala.
     * 
     * @param andar O número a ser definido para o andar da sala.
     */   
    void set_andar(int andar);

    /**
     * @brief Retorna a lista de empresas associadas à sala.
     * 
     * @return std::vector<empresa> Um vetor contendo as empresas locatárias.
     */
    vector<empresa> get_empresas() const;

    /**
     * @brief Método virtual puro para calcular o preço da sala.
     * 
     * @return double O preço calculado da sala, com base em suas características.
     */
    virtual double calcula_preco() const = 0;

    /**
     * @brief Sobrecarga do operador < para comparar o andar de duas salas (salas em andares inferiores vêm primeiro).
     * 
     * @param outro Referência para outra sala a ser comparada.
     * 
     * @return bool Comparação de qual sala está em um andar mais baixo.
     */
    bool operator<(const sala &outro) const;

    /**
     * @brief Sobrecarga do operador + para adicionar uma empresa à lista de uma sala.
     * 
     * @param empresa Referência para outra empresa a ser adicionada.
     * 
     * @return sala& Referência à própria sala após a inserção da empresa.
     */
    sala &operator+(const empresa &empresa);
    
    /**
     * @brief Sobrecarga do operador - para remover uma empresa da lista de uma sala.
     * 
     * @param empresa Referência para outra empresa a ser removida.
     * 
     * @return sala& Referência à própria sala após a remoção da empresa.
     */
    sala &operator-(const empresa &empresa);
};

#endif // Fim da verificação de inclusão SALA_H