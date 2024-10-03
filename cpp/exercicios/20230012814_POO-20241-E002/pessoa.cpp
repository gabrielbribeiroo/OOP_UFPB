#include "pessoa.h" 

int pessoa::contador = 0; // Inicializa o contador estático

pessoa::pessoa(const string &n, int i): nome(n), idade(i) {
    contador++; // Incrementa o contador para cada objeto criado
}

pessoa::~pessoa() {
    contador--; // Decrementa o contador quando o objeto é destruído
}

string pessoa::get_nome() const {
    return nome; // Retorna o nome da pessoa
}

void pessoa::set_nome(const string &n) {
    nome = n; // Modifica o nome da pessoa
}

int pessoa::get_idade() const {
    return idade; // Retorna a idade da pessoa
}

void pessoa::set_idade(int i) {
    idade = i; // Modifica a idade da pessoa
}

int pessoa::get_contador() {
    return contador; // Retorna o contador estático dos objetos da classe pessoa
}

/*
Implementação do método virtual puro.
**Não deve haver uma implementação aqui, pois o método é puro e não pode ter uma implementação na classe base.**
// Este método deve ser implementado nas classes derivadas.
*/
void pessoa::exibir_informacoes() const {}

bool pessoa::operator==(const pessoa &outro) const {
    return (nome == outro.nome && idade == outro.idade); // Sobrecarga do operador ==
}