/**
 * @file jogador.cpp
 * @brief Este arquivo contém a implementação da classe jogador.
 * 
 * A classe jogador demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "jogador.h" // Inclui o cabeçalho correspondente

jogador::jogador(const string &n, int i, double s, const string &p, int g)
    : membro_clube(n, i, s), posicao(p), gols_marcados(g) {} // Construtor
jogador::~jogador() {} // Destrutor

// Métodos getters e setters
string jogador::get_posicao() const {
    return posicao;
}
void jogador::set_posicao(const string &p) {
    this->posicao = p;
}
int jogador::get_gols_marcados() const {
    return gols_marcados;
}
void jogador::set_gols_marcados(int g) {
    this->gols_marcados = g;
}

double jogador::calcular_salario() const {
    return get_salario() + (gols_marcados * 100); // Salário + bônus por gols marcados
}

bool jogador::operator<(const jogador &outro) const {
    return this->gols_marcados < outro.gols_marcados; // Sobrecarga do operador <
}