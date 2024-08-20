// Inclusão dos cabeçalhos das classes
#include "pais.h"
#include "modalidade.h"
#include "atleta.h"
#include "medalha.h"
#include <memory> // Inclui a biblioteca para usar ponteiros inteligentes
#include <iostream> // Inclui a biblioteca para operações de entrada/saída

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string nome_pais, continente, nome_modalidade, nome_atleta, tipo_medalha;
    bool is_individual;
    int ano_medalha;

    // Solicitando informações do país
    cout << "Digite o nome do país: ";
    std::getline(cin, nome_pais);
    cout << "Digite o continente do país: ";
    std::getline(cin, continente);

    auto pais = std::make_unique<Pais>(nome_pais, continente); // Criação do objeto da classe Pais

    // Solicitando informações da modalidade
    cout << "Digite o nome da modalidade: ";
    std::getline(cin, nome_modalidade);
    cout << "A modalidade é individual? (1 para sim, 0 para não): ";
    cin >> is_individual;
    cin.ignore(); // Ignorar o newline que ficou no buffer

    auto modalidade = std::make_unique<Modalidade>(nome_modalidade, is_individual); // Criação do objeto da classe Modalidade

    // Solicitando informações do atleta
    cout << "Digite o nome do atleta: ";
    std::getline(cin, nome_atleta);

    // Criando o objeto Atleta
    auto player = std::make_unique<Atleta>(nome_atleta, std::move(pais), std::move(modalidade)); // Criação do objeto da classe Atleta

    // Solicitando informações da medalha
    cout << "Digite o tipo da medalha (Ouro, Prata, Bronze): ";
    std::getline(cin, tipo_medalha);
    cout << "Digite o ano da conquista da medalha: ";
    cin >> ano_medalha;
    cin.ignore(); // Ignorar o newline que ficou no buffer

    
    auto medal = std::make_unique<Medalha>(tipo_medalha, ano_medalha, std::move(player), std::move(modalidade)); // Criação do objeto da classe Medalha

    medal->print_info(); // Exibindo informações da medalha

    cout << "Fim do programa." << endl; // Encerramento do programa

    return 0;
}
