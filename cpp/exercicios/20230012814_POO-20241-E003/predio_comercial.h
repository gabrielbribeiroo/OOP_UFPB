#ifndef PREDIOCOMERCIAL_H // Verifica se o cabeçalho já foi incluído, para evitar inclusões múltiplas
#define PREDIOCOMERCIAL_H // Define um novo cabeçalho

#include "sala.h"

/**
 * @class predio_comercial
 * @brief Classe que representa um prédio comercial que gerencia várias salas.
 *
 * A classe predio_comercial gerencia informações sobre a lista de várias salas. 
 * Também ordena as salas por andar, e sobrecarrega os operadores + e -.
 */
class predio_comercial {
private: // Definição dos atributos de encapsulamento private (acessados somente dentro da classe)
    vector<sala*> lista_de_salas; // Vetor com a lista de salas
public: // Definição dos atributos de encapsulamento public (acessados dentro e fora da classe)
    /**
     * @brief Sobrecarga do operador + para adicionar uma sala ao prédio comercial.
     * 
     * @param sala Ponteiro para a sala a ser adicionada.
     * 
     * @return predio_comercial& Referência ao próprio prédio comercial após a adição da sala.
     */
    predio_comercial &operator+(sala *sala);

    /**
     * @brief Sobrecarga do operador - para remover uma sala do prédio comercial.
     * 
     * @param sala Ponteiro para a sala a ser removida.
     * 
     * @return predio_comercial& Referência ao próprio prédio comercial após a remoção da sala.
     */
    predio_comercial &operator-(sala *sala);

    /**
     * @brief Lista todas as salas do prédio comercial e suas respectivas empresas.
     * 
     * Exibe as salas em ordem crescente de andar, juntamente com as empresas associadas a cada sala,
     * listadas por ordem de idade (empresas mais antigas aparecem primeiro).
     */
    void listar_salas() const;
};

#endif // Fim da verificação de inclusão PREDIOCOMERCIAL_H