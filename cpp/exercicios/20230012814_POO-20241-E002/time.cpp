/**
 * @file time.cpp
 * @brief Este arquivo contém a implementação da classe time.
 * 
 * A classe time demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "time.h" // Inclui o cabeçalho correspondente

time::time(const string &n, tecnico *t, int p) 
    : nome(n), tecnico_ptr(t), pontuacao(p) {} // Construtor
time::~time() {} // Destrutor

// Métodos getters e setters
string time::get_nome() const {
    return nome;
}
void time::set_nome(const string &n) {
    this->nome = n;
}
tecnico *time::get_tecnico() const {
    return tecnico_ptr;
}
void time::set_tecnico(tecnico *t) {
    this->tecnico_ptr = t;
}
int time::get_pontuacao() const {
    return pontuacao;
}
void time::set_pontuacao(int p) {
    this->pontuacao = p;
}

void time::adicionar_jogador(const jogador &j) {
    jogadores.push_back(j); // Adiciona o jogador à pilha
}

void time::registrar_resultado(char r) {
    if (r == 'V') {
        pontuacao += 3; // Adiciona 3 pontos para o caso de vitória
    } else if (r == 'E') {
        pontuacao += 1; // Adiciona 1 ponto para o caso de empate
    }
}

// Exibe as informações do time
void time::exibir_informacoes() const {
    cout << "Nome do time: " << nome << "\n";
    cout << "Técnico: " << tecnico_ptr->get_nome() << "\n";
    cout << "Pontuação: " << pontuacao << "\n";
    cout << "Jogadores:\n";
    for (const auto &jogador : jogadores) {
        cout << "- " << jogador.get_nome() << " (Gols: " << jogador.get_gols_marcados() << ")\n";
    }
}

bool time::operator<(const time &outro) const {
    return this->pontuacao < outro.pontuacao; // Sobrecarga do operador < (compara as pontuações)
}