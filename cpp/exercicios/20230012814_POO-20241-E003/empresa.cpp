/**
 * @file empresa.cpp
 * @brief Este arquivo contém a implementação da classe empresa.
 * 
 * A classe empresa demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-27
 */

#include "empresa.h" // Inclui o cabeçalho correspondente
#include <stdexcept> // Biblioteca para tratamento de exceções

using std::invalid_argument;

empresa::empresa(const string &n, int i): nome_da_empresa(n) {
    if (i < 0) throw invalid_argument("Idade nao pode ser negativa"); // Exceção para idade negativa
    this->idade_da_empresa = i;
} // Construtor
empresa::~empresa() {} // Destrutor

// Métodos getters e setters
string empresa::get_nome() const {
    return nome_da_empresa;
}
void empresa::set_nome(const string &n) {
    this->nome_da_empresa = n;
}
int empresa::get_idade() const {
    return idade_da_empresa;
}
void empresa::set_idade(int i) {
    if (i < 0) throw invalid_argument("Idade nao pode ser negativa"); // Exceção para idade negativa
    this->idade_da_empresa = i;
}

// Sobrecarga do operador < que compara duas idades de duas empresas
bool empresa::operator<(const empresa &outro) const {
    return idade_da_empresa < outro.idade_da_empresa; // Se a empresa é mais antiga que a outra ou não
}