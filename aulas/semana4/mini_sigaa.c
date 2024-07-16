#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 40
#define TAM_TURMA 10

typedef struct {
  char nome[TAM_NOME];
  int idade;
} t_pessoa;

typedef struct {
  t_pessoa p;
  int matricula;
  double cra;	
} t_aluno;

typedef struct {
  t_pessoa p;
  int siape;
  int departamento;
} t_professor;

typedef struct {
  int sala;
  int horario;
  t_aluno* alunos[TAM_TURMA];
  t_professor* prof;
} t_turma;

void cadastrar_aluno(t_aluno* a) {
  int i, m;
  double c;
  printf("Digite a idade do aluno: ");
  scanf("%d", &i);
  while ((i<0) || (i>200)) {
    printf("Digite a idade do aluno: ");
    scanf("%d", &i);
  }
}


int main(void) {
  t_aluno a1;
  t_professor p1;

  strcpy(&p1.p.nome, "Ana Silva");
  p1.p.idade = 40;
  p1.departamento = 10;

  return 0;
}