/**
 * @file membro_clube.cpp
 * @brief Este arquivo contém a implementação da classe membro_clube.
 * 
 * A classe membro_clube demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "membro_clube.h" // Inclui o cabeçalho correspondente

membro_clube::membro_clube(const string &n, int i, double s): pessoa(n, i), salario(s) {} // Construtor
membro_clube::~membro_clube() {} // Destrutor

// Métodos getters e setters
double membro_clube::get_salario() const {
    return salario; 
}
void membro_clube::set_salario(double s) {
    salario = s; 
}

// Sobrecarga do operador <<
ostream &operator<<(ostream &os, const membro_clube &membro) {
    os << "Nome: " << membro.get_nome() << ", Idade: " << membro.get_idade() << ", Salário: " << membro.get_salario();
    return os;
}