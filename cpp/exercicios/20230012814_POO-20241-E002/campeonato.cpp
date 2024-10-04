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

void campeonato::adicionar_time(const time &t) {
    times.push_back(t); // Adiciona o time na pilha
}

void campeonato::adicionar_jogo(const jogo &j) {
    jogos.push_back(j); // Adiciona um jogo na pilha
}

// Exibe a classificação dos times no campeonato.
void campeonato::exibir_classificacao() const {
    vector<time> classificacao = times;
    
    // Ordena os times pela pontuação, do maior para o menor
    std::sort(classificacao.begin(), classificacao.end(), [](const time &a, const time &b) {
        return a.get_pontuacao() > b.get_pontuacao();
    });

    cout << "Classificação do campeonato: " << nome_campeonato << "\n";
    for (size_t i = 0; i < classificacao.size(); ++i) {
        cout << i + 1 << ". " << classificacao[i].get_nome() << " - " 
                  << classificacao[i].get_pontuacao() << " pontos\n";
    }
}