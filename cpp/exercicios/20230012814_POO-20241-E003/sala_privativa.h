#ifndef SALAPRIVATIVA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define SALAPRIVATIVA_H // Define um novo cabeçalho

#include "sala.h" // Inclui o cabeçalho base

/**
 * @class sala_privativa
 * @brief Classe derivada da classe sala que representa uma sala privativa com capacidade máxima de pessoas.
 *
 * A classe sala_privativa mantém informações sobre a capacidade máxima de pessoas. 
 * Também sobrescreve o método virtual para calcular preço.
 */
class sala_privativa : public sala {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    int capacidade_maxima_de_pessoas; // Número da capacidade máxima de pessoas comportadas na sala
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor da classe derivada sala_privativa.
     * 
     * @param numero Número da sala. 
     * @param andar Andar da sala.
     * @param capacidade Capacidade de pessoas da sala.
     */
    sala_privativa(int numero, int andar, int capacidade);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~sala_privativa();

    /**
     * @brief Obtém a capacidade máxima de pessoas.
     * 
     * @return int O número da capacidade máxima de pessoas da sala.
     */
    int get_capacidade() const;

    /**
     * @brief Define a capacidade da sala.
     * 
     * @param capacidade O número a ser definido para a capacidade da sala.
     */   
    void set_capacidade(int capacidade);

    /**
     * @brief Implementa o cálculo de preço específico para sala privativa.
     * 
     * @return double O preço calculado com base na capacidade máxima de pessoas.
     */
    double calcula_preco() const override;
};

#endif // Fim da verificação de inclusão SALAPRIVATIVA_H