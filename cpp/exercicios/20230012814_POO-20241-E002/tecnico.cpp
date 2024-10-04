/**
 * @file tecnico.cpp
 * @brief Este arquivo contém a implementação da classe tecnico.
 * 
 * A classe tecnico representa um técnico de futebol que herda de membro_clube
 * e implementa funcionalidades específicas, como calcular o salário com base em
 * anos de experiência.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "tecnico.h" // Inclui o cabeçalho correspondente

tecnico::tecnico(const string &n, int i, double s, int e)
    : membro_clube(n, i, s), experiencia(e) {} // Construtor
tecnico::~tecnico() {} // Destrutor

// Métodos getters e setters
int tecnico::get_experiencia() const {
    return experiencia;
}
void tecnico::set_experiencia(int e) {
    this->experiencia = e;
}

double tecnico::calcular_salario() const {
    return get_salario() + (experiencia * 200); // Calcula o salário do técnico
}
