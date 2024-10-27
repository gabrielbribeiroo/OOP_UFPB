/**
 * @file sala_compartilhada.cpp
 * @brief Este arquivo contém a implementação da classe sala_compartilhada.
 * 
 * A classe sala_compartilhada demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-27
 */

#include "sala_compartilhada.h" // Inclui o cabeçalho correspondente

sala_compartilhada::sala_compartilhada(int n, int a, int e): sala(n, a), numero_de_estacoes_de_trabalho_disponiveis(e) {} // Construtor
sala_compartilhada::~sala_compartilhada() {} // Destrutor

// Métodos getters e setters
int sala_compartilhada::get_estacoes() const { 
    return numero_de_estacoes_de_trabalho_disponiveis; 
}
void sala_compartilhada::set_estacoes(int e) { 
    this->numero_de_estacoes_de_trabalho_disponiveis = e; 
}

// Calcula o preço da sala
double sala_compartilhada::calcula_preco() const {
    return numero_de_estacoes_de_trabalho_disponiveis * 30.0; 
}