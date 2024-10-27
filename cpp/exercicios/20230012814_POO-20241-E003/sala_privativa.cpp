/**
 * @file sala_privativa.cpp
 * @brief Este arquivo contém a implementação da classe sala_privativa.
 * 
 * A classe sala_privativa demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-27
 */

#include "sala_privativa.h" // Inclui o cabeçalho correspondente

sala_privativa::sala_privativa(int n, int a, int c): sala(n, a), capacidade_maxima_de_pessoas(c) {} // Construtor
sala_privativa::~sala_privativa() {} // Destrutor

// Métodos getters e setters
int sala_privativa::get_capacidade() const { 
    return capacidade_maxima_de_pessoas; 
}
void sala_privativa::set_capacidade(int c) { 
    this->capacidade_maxima_de_pessoas = c; 
}

// Calcula o preço da sala
double sala_privativa::calcula_preco() const {
    return capacidade_maxima_de_pessoas * 50.0; 
}