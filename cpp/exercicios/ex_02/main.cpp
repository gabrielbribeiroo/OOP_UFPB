// Inclusão dos cabeçalhos das classes
#include "pais.h"
#include "modalidade.h"
#include "atleta.h"
#include "medalha.h"
#include <memory> // Inclui a biblioteca para usar ponteiros inteligentes
#include <iostream> // Inclui a biblioteca para operações de entrada/saída

using std::cout;
using std::endl;
using std::string;

int main() {
    auto usa = std::make_unique<Pais>("United States of America", "America do Norte");
    // Criação do objeto da classe Pais
    // (USA, América do Norte) 

    auto basketball = std::make_unique<Modalidade>("Basquete", false);
    // Criação do objeto da classe Modalidade
    // (Basquete, Coletivo)
     
    auto player = std::make_unique<Atleta>("Lebron James", std::move(usa), std::move(basketball));
    // Criação do objeto da classe Atleta
    // Associa o país e a modalidade ao atleta
    // (Lebron James, United States of America, America do Norte, Basquete, Coletivo)
    
    auto medal = std::make_unique<Medalha>("Ouro", 2024, std::move(player), std::make_unique<Modalidade>("Basquete", false));
    // Criação do objeto da classe Medalha
    // (Ouro, 2024, Lebron James, United States of America, America do Norte, Basquete, Coletivo)

    medal->print_info(); // Exibe informações da medalha
    
    cout << "Fim do programa." << endl; // Encerramento do programa

    return 0;
}
