/**
 * @file campeonato.cpp
 * @brief Este arquivo contém a implementação da classe campeonato.
 * 
 * A classe campeonato demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "campeonato.h" // Inclui o cabeçalho correspondente

campeonato::campeonato(const string &n): nome_campeonato(n) {} // Construtor
campeonato::~campeonato() {} // Destrutor

// Métodos getters e setters
string campeonato::get_nome_campeonato() const {
    return nome_campeonato;
}
void campeonato::set_nome_campeonato(const string &n) {
    this->nome_campeonato = n;
}

void campeonato::adicionar_time(time &t) {
    times.push_back(&t); // Adiciona o ponteiro para o time
}

void campeonato::adicionar_jogo(const jogo &j) {
    jogos.push_back(j); // Adiciona um jogo na pilha
}

// Exibe a classificação dos times no campeonato.
void campeonato::exibir_classificacao() const {
    // Faz uma cópia do vetor de times para não alterar a ordem original
    vector<time*> times_ordenados = times;

    // Ordena os times por pontuação em ordem decrescente
    sort(times_ordenados.begin(), times_ordenados.end(), [](time* a, time* b) {
        return a->get_pontuacao() > b->get_pontuacao();
    });

    // Exibe os times ordenados pela maior pontuação
    cout << "Tabela: " << nome_campeonato << "\n";
    for (const auto &time : times_ordenados) {
        std::cout << time->get_nome() << " - " << time->get_pontuacao() << " pontos\n";
    }
}