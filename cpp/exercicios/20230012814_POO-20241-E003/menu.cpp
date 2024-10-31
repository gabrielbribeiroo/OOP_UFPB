#include <iostream> // Inclusão da biblioteca padrão de entrada e saída de C++
#include <string> // Inclusão da biblioteca para manipulação de string
#include <algorithm>

// Inclusão dos cabeçalhos das classes do projeto
#include "predio_comercial.h"
#include "sala_privativa.h"
#include "sala_compartilhada.h"
#include "empresa.h"

// Namespace std
using std::cin;
using std::cout;
using std::endl;
using std::find_if;

/**
 * @brief Exibe o menu interativo de 6 opções para o usuário.
 */   
void exibir_menu() {
    cout << "\n=== Sistema de Gerenciamento de Locacao de Salas ===" << endl;
    cout << "1. Adicionar sala" << endl;
    cout << "2. Remover sala" << endl;
    cout << "3. Adicionar empresa a uma sala" << endl;
    cout << "4. Remover empresa de uma sala" << endl;
    cout << "5. Listar todas as salas e empresas" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    predio_comercial predio;
    int opcao;

    do {
        exibir_menu();
        cin >> opcao;

        switch (opcao) {
            // Adicionar sala
            case 1: {
                int tipo, numero, andar;
                cout << "Escolha o tipo de sala [1 - Privativa, 2 - Compartilhada]: ";
                cin >> tipo;
                cout << "Numero da sala: ";
                cin >> numero;
                cout << "Andar: ";
                cin >> andar;

                if (tipo == 1) {
                    int capacidade;
                    cout << "Capacidade maxima de pessoas: ";
                    cin >> capacidade;
                    sala_privativa *sala = new sala_privativa(numero, andar, capacidade);
                    predio + sala;
                } 
                else if (tipo == 2) {
                    int estacoes;
                    cout << "Numero de estacoes de trabalho disponiveis: ";
                    cin >> estacoes;
                    sala_compartilhada *sala = new sala_compartilhada(numero, andar, estacoes);
                    predio + sala;
                } 
                else {
                    cout << "Tipo de sala invalido." << endl;
                }
                break;
            }

            // Remover sala
            case 2: {
                int numero;
                cout << "Numero da sala a ser removida: ";
                cin >> numero;
                sala *sala_a_remover = predio.buscar_sala_por_numero(numero); // Supondo que haja um método buscar_sala_por_numero
                if (sala_a_remover) {
                    predio - sala_a_remover;
                    cout << "Sala removida com sucesso." << endl;
                } 
                else {
                    cout << "Sala nao encontrada." << endl;
                }
                break;
            }

            // Adicionar empresa a uma sala
            case 3: {
                int numero;
                string nome;
                int idade;
                cout << "Numero da sala para adicionar a empresa: ";
                cin >> numero;
                sala *sala = predio.buscar_sala_por_numero(numero);
                if (sala) {
                    cout << "Nome da empresa: ";
                    cin >> nome;
                    cout << "Idade da empresa (em anos): ";
                    cin >> idade;
                    empresa empresa(nome, idade);
                    *sala + empresa;
                } 
                else {
                    cout << "Sala nao encontrada." << endl;
                }
                break;
            }

            // Remover uma empresa de uma sala
            case 4: {                
                int numero_sala;
                cout << "Digite o numero da sala: ";
                cin >> numero_sala;

                sala *sala_selecionada = predio.buscar_sala_por_numero(numero_sala);
                if (sala_selecionada) {
                    string nome_empresa;
                    cout << "Digite o nome da empresa a ser removida: ";
                    cin >> nome_empresa;

                    // Procurar a empresa na lista de locatárias da sala
                    auto empresas = sala_selecionada->get_empresas();
                    auto it = std::find_if(empresas.begin(), empresas.end(),
                        [&nome_empresa](const empresa &e) { return e.get_nome() == nome_empresa; });

                    if (it != empresas.end()) {
                        // Remover a empresa da sala usando o operador -
                        *sala_selecionada - *it;
                        cout << "Empresa " << nome_empresa << " removida da sala " << numero_sala << "." << endl;
                    } 
                    else {
                        cout << "Empresa nao encontrada na sala." << endl;
                    }
                } 
                else {
                    cout << "Sala nao encontrada." << endl;
                }
                break;
            }

            // Listar todas as salas e empresas
            case 5: {
                predio.listar_salas();
                break;
            }

            // Sair do programa
            case 0:
                cout << "Saindo do sistema..." << endl;
                break;

            default:
                cout << "Opção invalida. Tente novamente!" << endl;
        }

    } while (opcao != 0);

    return 0;
}