/**
 * @file pessoa.cpp
 * @brief Este arquivo contém a implementação da classe pessoa.
 * 
 * A classe pessoa demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "pessoa.h" // Inclui o cabeçalho correspondente 

int pessoa::contador = 0; // Inicializa o contador estático

pessoa::pessoa(const string &n, int i): nome(n), idade(i) {
    contador++; // Incrementa o contador para cada objeto criado
}

pessoa::~pessoa() {
    contador--; // Decrementa o contador quando o objeto é destruído
}

string pessoa::get_nome() const {
    return nome; // Retorna o nome da pessoa
}

void pessoa::set_nome(const string &n) {
    nome = n; // Modifica o nome da pessoa
}

int pessoa::get_idade() const {
    return idade; // Retorna a idade da pessoa
}

void pessoa::set_idade(int i) {
    idade = i; // Modifica a idade da pessoa
}

int pessoa::get_contador() {
    return contador; // Retorna o contador estático dos objetos da classe pessoa
}

bool pessoa::operator==(const pessoa &outro) const {
    return (nome == outro.nome && idade == outro.idade); // Sobrecarga do operador ==
}