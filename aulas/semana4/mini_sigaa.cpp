#include <iostream>
#include <string.h>

#define TAM_TURMA 10
#define TAM_NOME 40

class pessoa {
    char nome[TAM_NOME];
    int idade;
    public:
        char *get_nome() {
            return nome;
        }
        void set_nome(char *n) {
            strcpy(nome, n);
        }
        int get_idade() {
            return idade;
        }
        void set_idade(int i) {
            idade = i;
        }
};

class aluno : public pessoa {
    int matricula;
    double cra;	
    public: 
        int get_matricula() {
            return matricula;
        }
        void set_matricula(int m) {
            matricula = m;
        }
};

class professor : public pessoa { // Herança
    int siape;
    int departamento;
    public: 
        int get_siape() {
            return siape;
        }
        void set_siape(int s) {
            siape = s;
        }
};

class turma {
    int sala;
    int horario;
    aluno *alunos[TAM_TURMA];
    int qtd_alunos;
    professor *prof;
};

int main(void) {
    // A definição da classe já define um tipo
    aluno a1; // a1 é um objeto/instância da classe/tipo aluno
    professor p1; // p1 um objeto/instância da classe/tipo aluno
    pessoa *pp1;

    a1.set_idade(18);
    p1.set_idade(33);	
    a1.set_matricula(1011);
    p1.set_siape(9999);

    printf("Idade a1: %d\n", a1.get_idade());
    printf("Matricula a1: %d\n", a1.get_matricula());
    printf("Idade p1: %d\n", p1.get_idade());
    printf("Siape p1: %d\n", p1.get_siape());

    return 0;
}