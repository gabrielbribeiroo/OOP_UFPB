#include <iostream>
#include "campeonato.h"
#include "jogo.h"
#include "tecnico_jogador.h"
#include "juiz.h"

int main() {
    // Criando o campeonato
    campeonato camp("Campeonato Quadrangular");

    // Cadastrando quatro times
    tecnico tec1("Pep Guardiola", 53, 5000, 10);
    tecnico tec2("Jurgen Klopp", 57, 5200, 12);
    tecnico tec3("Alex Ferguson", 82, 5400, 15);
    tecnico_jogador tec_jog("Carlo Ancelotti", 38, 4800, "Atacante", 10, 8, 1000);

    time time1("Time A", &tec1);
    time time2("Time B", &tec2);
    time time3("Time C", &tec3);
    time time4("Time D", &tec_jog);

    // Adicionando jogadores a cada time (5 jogadores por time)
    for (int i = 1; i <= 5; ++i) {
        time1.adicionar_jogador(jogador("Lucas" + std::to_string(i), 25 + i, 2000, "Atacante", 5 * i));
        time2.adicionar_jogador(jogador("Luan" + std::to_string(i), 24 + i, 2100, "Meio-campo", 4 * i));
        time3.adicionar_jogador(jogador("Paulo" + std::to_string(i), 26 + i, 2200, "Zagueiro", 3 * i));
        time4.adicionar_jogador(jogador("Cristiano" + std::to_string(i), 23 + i, 2300, "Goleiro", 2 * i));
    }

    // Adicionando times ao campeonato
    camp.adicionar_time(time1);
    camp.adicionar_time(time2);
    camp.adicionar_time(time3);
    camp.adicionar_time(time4);

    // Cadastrando dois juízes
    juiz juiz1("Fernando Mendes", 42, 50);
    juiz juiz2("Ana Paula", 35, 40);

    // Cadastrando jogos (cada time jogará contra todos os outros)
    jogo jogo1(&time1, &time2, &juiz1);
    jogo1.registrar_resultado(2, 1); // Time 1 venceu por 2 a 1
    camp.adicionar_jogo(jogo1);

    jogo jogo2(&time1, &time3, &juiz2);
    jogo2.registrar_resultado(1, 3); // Time 3 venceu por 3 a 1
    camp.adicionar_jogo(jogo2);

    jogo jogo3(&time1, &time4, &juiz1);
    jogo3.registrar_resultado(0, 0); // Empate 0 a 0
    camp.adicionar_jogo(jogo3);

    jogo jogo4(&time2, &time3, &juiz2);
    jogo4.registrar_resultado(1, 1); // Empate 1 a 1
    camp.adicionar_jogo(jogo4);

    jogo jogo5(&time2, &time4, &juiz1);
    jogo5.registrar_resultado(2, 3); // Time 4 venceu por 3 a 2
    camp.adicionar_jogo(jogo5);

    jogo jogo6(&time3, &time4, &juiz2);
    jogo6.registrar_resultado(2, 2); // Empate 2 a 2
    camp.adicionar_jogo(jogo6);

    // Exibindo a tabela de classificação final
    camp.exibir_classificacao();

    return 0;
}
