#include "tecnico_jogador.h" // Inclui o cabeçalho correspondente

// Construtor para inicializar a posição e o número de gols marcados do jogador
jogador::jogador(const string &posicao, int gols): posicao(posicao), gols_marcados(gols) {}
jogador::~jogador() {} // Destrutor para liberar os recursos do jogador

// Leitura e modificação da posição do jogador
string jogador::get_posicao() const {
    return posicao;
}
void jogador::set_posicao(const string &p) {
    posicao = p;
}

// Leitura e modificação do número de gols marcados do jogador
int jogador::get_gols_marcados() const {
    return gols_marcados;
}
void jogador::set_gols_marcados(int g) {
    gols_marcados = g;
}
void jogador::adicionar_gols(int gols) {
    assert(gols >= 0); // Gols não podem ser negativos
    this->gols_marcados += gols;
}

// Calcula o salário do jogador, a partir do número de gols marcados
double jogador::calcular_salario() const {
    return (1000)*gols_marcados;
}

// Exibe as informações do jogador, incluindo posição, gols e salário
void jogador::print_info() const {
    cout << "-------Jogador-------" << endl;
    cout << "Posicao: " << posicao << endl;
    cout << "Gols marcados: " << gols_marcados << endl;
    cout << "Salario: R$" << calcular_salario() << endl;
} 