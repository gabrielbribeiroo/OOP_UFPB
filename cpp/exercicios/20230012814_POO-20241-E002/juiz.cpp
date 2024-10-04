/**
 * @file juiz.cpp
 * @brief Este arquivo contém a implementação da classe juiz.
 * 
 * A classe juiz demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "juiz.h" // Inclui o cabeçalho correspondente

juiz::juiz(const string &n, int i, int p) : pessoa(n, i), partidas_arbitradas(p) {} // Construtor
juiz::~juiz() {} // Destrutor

// Métodos getters e setters
int juiz::get_partidas_arbitradas() const {
    return partidas_arbitradas;
}
void juiz::set_partidas_arbitradas(int p) {
    this->partidas_arbitradas = partidas_arbitradas;
}

// Incrementa o número de partidas arbitradas
void juiz::incrementar_partidas_arbitradas() {
    partidas_arbitradas++;
}

// Exibe as informações do juiz
void juiz::exibir_informacoes() const {
    cout << "Nome: " << get_nome() << ", Idade: " << get_idade() << ", Partidas Arbitradas: " << partidas_arbitradas << endl;
}