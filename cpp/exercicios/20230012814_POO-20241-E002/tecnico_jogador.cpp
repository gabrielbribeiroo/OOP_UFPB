/**
 * @file tecnico_jogador.cpp
 * @brief Este arquivo contém a implementação da classe tecnico_jogador.
 * 
 * A classe tecnico_jogador demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "tecnico_jogador.h" // Inclui o cabeçalho correspondente

tecnico_jogador::tecnico_jogador(const string &n, int i, double s, const string &p, int g, int e, double b)
    : jogador(n, i, s, p, g), tecnico(n, i, s, e), bonus_duplo_papel(b) {} // Construtor
tecnico_jogador::~tecnico_jogador() {} // Destrutor

// Métodos getters e setters
double tecnico_jogador::get_bonus_duplo_papel() const {
    return bonus_duplo_papel;
}
void tecnico_jogador::set_bonus_duplo_papel(double b) {
    this->bonus_duplo_papel = b;
}

double tecnico_jogador::calcular_salario() const {
    return jogador::calcular_salario() + tecnico::calcular_salario() + bonus_duplo_papel; // Calcular a soma dos salários
}

// Sobrecarga do operador <<
ostream &operator<<(ostream &os, const tecnico_jogador &t) {
    // Por se tratarem da mesma pessoa, para resolver a ambiguidade, selecionei o nome e idade pela classe jogador
    os << "Nome: " << t.jogador::get_nome() 
       << ", Idade: " << t.jogador::get_idade() 
       << ", Posição: " << t.get_posicao() 
       << ", Gols Marcados: " << t.get_gols_marcados()
       << ", Experiência: " << t.get_experiencia() 
       << " anos, Salário Total: " << t.calcular_salario() 
       << ", Bônus Duplo Papel: " << t.get_bonus_duplo_papel();
    return os;
}