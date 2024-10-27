/**
 * @file sala.cpp
 * @brief Este arquivo contém a implementação da classe sala.
 * 
 * A classe sala demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-27
 */

#include "sala.h" // Inclui o cabeçalho correspondente
#include <algorithm>

using std::remove;

sala::sala(int n, int a): numero_da_sala(n), andar(a) {} // Construtor
sala::~sala() {} // Destrutor

// Métodos getters e setters
int sala::get_numero() const { 
    return numero_da_sala; 
}
void sala::set_numero(int n) { 
    this->numero_da_sala = n; 
}
int sala::get_andar() const { 
    return andar;
}
void sala::set_andar(int a) { 
    this->andar = andar; 
}

vector<empresa> sala::get_empresas() const { 
    return lista_de_empresas_locatarias; // Retorna o vetor listando as empresas
}

// Sobrecarga do operador < que compara os andares de duas salas
bool sala::operator<(const sala &outro) const {
    return andar < outro.andar; // Se a sala localiza-se em um andar mais baixo que a outra ou não
}

// Sobrecarga do operador + que aloca uma nova empresa à uma sala
sala &sala::operator+(const empresa &e) {
    lista_de_empresas_locatarias.push_back(e); // Adiciona a empresa na pilha
    return *this; // Retorna o vetor alterado
}

// Sobrecarga do operador - que desaloca uma empresa de uma sala
sala &sala::operator-(const empresa &e) {
    lista_de_empresas_locatarias.erase(
        remove(lista_de_empresas_locatarias.begin(), lista_de_empresas_locatarias.end(), e),
        lista_de_empresas_locatarias.end()
    ); // Remove a empresa 
    return *this; // Retorna o vetor alterado
}