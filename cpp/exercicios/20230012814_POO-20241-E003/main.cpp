// Inclusão dos cabeçalhos das classes do projeto
#include "empresa.h"
#include "sala_privativa.h"
#include "sala_compartilhada.h"
#include "predio_comercial.h"

#include <iostream> // Inclusão da biblioteca padrão de C++

using std::cerr;
using std::endl;
using std::exception;

int main() {
    try {
        empresa e1("Empresa A", 10);
        empresa e2("Empresa B", 5);

        sala_privativa s1(101, 1, 15);
        s1 + e1 + e2;

        predio_comercial predio;
        predio + &s1;

        predio.listar_salas();
    } 
    catch (const exception &e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}