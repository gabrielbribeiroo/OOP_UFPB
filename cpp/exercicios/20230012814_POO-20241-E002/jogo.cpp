/**
 * @file jogo.cpp
 * @brief Este arquivo contém a implementação da classe jogo.
 * 
 * A classe jogo demonstra o uso de Doxygen para documentar
 * uma classe e seus métodos em C++.
 * 
 * @author Gabriel Ribeiro
 * @version 1.0
 * @date 2024-10-03
 */

#include "jogo.h" // Inclui o cabeçalho correspondente

jogo::jogo(time *tc, time *tv, juiz *j)
    : time_casa(tc), time_visitante(tv), juiz_principal(j),
      gols_time_casa(0), gols_time_visitante(0) {} // Construtor
jogo::~jogo() {} // Destrutor

// Métodos getters e setters
time *jogo::get_time_casa() const {
    return time_casa;
}
void jogo::set_time_casa(time *tc) {
    this->time_casa = tc;
}
time *jogo::get_time_visitante() const {
    return time_visitante;
}
void jogo::set_time_visitante(time *tv) {
    this->time_visitante = tv;
}
juiz *jogo::get_juiz_principal() const {
    return juiz_principal;
}
void jogo::set_juiz_principal(juiz *j) {
    this->juiz_principal = j;
}
int jogo::get_gols_time_casa() const {
    return gols_time_casa;
}
void jogo::set_gols_time_casa(int g) {
    this->gols_time_casa = g;
}
int jogo::get_gols_time_visitante() const {
    return gols_time_visitante;
}
void jogo::set_gols_time_visitante(int g) {
    this->gols_time_visitante = g;
}

void jogo::registrar_resultado(int gc, int gv) {
    this->gols_time_casa = gc;
    this->gols_time_visitante = gv;

    // Verificação de quem fez mais gols para determinar o resultado
    if (gc > gv) {
        time_casa->registrar_resultado('V');
        time_visitante->registrar_resultado('D');
    } else if (gc < gv) {
        time_casa->registrar_resultado('D');
        time_visitante->registrar_resultado('V');
    } else {
        time_casa->registrar_resultado('E');
        time_visitante->registrar_resultado('E');
    }
}

// Exibe os nomes dos times, o placar da partida e o juiz responsável.
void jogo::exibir_informacoes() const {
    cout << "Time da Casa: " << time_casa->get_nome() << " (" << gols_time_casa << " gols)\n";
    cout << "Time Visitante: " << time_visitante->get_nome() << " (" << gols_time_visitante << " gols)\n";
    cout << "Juiz Principal: " << juiz_principal->get_nome() << "\n";
}