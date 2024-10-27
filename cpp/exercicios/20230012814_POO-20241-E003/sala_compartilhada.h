#ifndef SALACOMPARTILHADA_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define SALACOMPARTILHADA_H // Define um novo cabeçalho

#include "sala.h" // Inclui o cabeçalho base

/**
 * @class sala_compartilhada
 * @brief Classe derivada da classe sala que representa uma sala compartilhada com estações de trabalho.
 *
 * A classe sala_compartilhada mantém informações sobre o número de estações de trabalho disponíveis. 
 * Também sobrescreve o método virtual para calcular preço.
 */
class sala_compartilhada : public sala {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    int numero_de_estacoes_de_trabalho_disponiveis; // Número de estações de trabalho disponíveis na sala
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Construtor da classe derivada sala_compartilhada.
     * 
     * @param numero Número da sala. 
     * @param andar Andar da sala.
     * @param estacoes Estações de trabalho da sala.
     */
    sala_compartilhada(int numero, int andar, int estacoes);

    /**
     * @brief Destrutor para liberar recursos e destruir o objeto ao final.
     */
    ~sala_compartilhada();

    /**
     * @brief Obtém a quantidade de estações de trabalho disponíveis.
     * 
     * @return int O número de estações de trabalho da sala.
     */
    int get_estacoes() const;

    /**
     * @brief Define a quantidade de estações de trabalho da sala.
     * 
     * @param estacoes O número a ser definido para as estações de trabalho da sala.
     */   
    void set_estacoes(int estacoes);

    /**
     * @brief Implementa o cálculo de preço específico para sala compartilhada.
     * 
     * @return double O preço calculado com base nas estações de trabalho disponíveis.
     */
    double calcula_preco() const override;
};

#endif // Fim da verificação de inclusão SALACOMPARTILHADA_H