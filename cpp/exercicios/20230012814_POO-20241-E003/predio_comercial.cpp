/**
 * @file predio_comercial.cpp
 * @brief Este arquivo contém a implementação da classe predio_comercial.
 * 
 * A classe predio_comercial demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-27
 */

#include "predio_comercial.h" // Inclui o cabeçalho correspondente
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;

// Sobrecarga do operador + que adiciona uma sala
predio_comercial &predio_comercial::operator+(sala *s) {
    lista_de_salas.push_back(s); // Adiciona a sala à pilha
    return *this; // Retorna o vetor alterado
}

// Sobrecarga do operador - que desaloca uma sala
predio_comercial &predio_comercial::operator-(sala *sala) {
    lista_de_salas.erase(
        std::remove(lista_de_salas.begin(), lista_de_salas.end(), sala),
        lista_de_salas.end()
    ); // Remove a sala 
    return *this; // Retorna o vetor alterado
}

// Lista das salas
void predio_comercial::listar_salas() const {
    vector<sala*> salas_ordenadas = lista_de_salas; // Cria uma cópia da lista original de salas para ordenação
    
    // Ordena as salas pelo andar usando uma função lambda que compara objetos da classe sala por meio do operador <
    sort(salas_ordenadas.begin(), salas_ordenadas.end(), [](sala *a, sala *b) { return *a < *b; });

    for (const auto &sala : salas_ordenadas) {
        cout << "Sala " << sala->get_numero() << " no andar " << sala->get_andar() << ":\n"; // Exibe o número e o andar de cada sala
        
        // Obtém a lista de empresas associadas à sala e as ordena por idade
        auto empresas = sala->get_empresas();
        sort(empresas.begin(), empresas.end());
        
        // Exibe o nome e a idade de cada empresa na sala
        for (const auto &empresa : empresas) {
            cout << " - Empresa: " << empresa.get_nome() << ", Idade: " << empresa.get_idade() << " anos" << endl;
        }
    }
}

sala *predio_comercial::buscar_sala_por_numero(int n) const {
    // Percorre cada ponteiro de sala na lista_de_salas
    for (sala *sala : lista_de_salas) {
        // Compara o número da sala com o número especificado
        if (sala->get_numero() == n) {
            return sala; // Retorna a sala se o número corresponder
        }
    }
    
    return nullptr;  // Retorna nullptr se a sala não for encontrada
}