#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define NOME_ALUNO_SIZE 40
#define NOME_TURMA_SIZE 20
#define TURMA_SIZE 20

typedef struct {
	int matricula;
	char nome[NOME_ALUNO_SIZE];
	double cra;
} t_aluno;

typedef struct {
	int id;
	char nome[NOME_TURMA_SIZE];
	int sala;
	t_aluno *alunos[TURMA_SIZE];
	int numero_de_alunos;
} t_turma;

void preenche_aluno(t_aluno *a, int m, char *n, double c) {
	a->matricula = m;
	strcpy(a->nome, n);
	a->cra = c;
}

void preenche_turma(t_turma *t, int i, char *n, int s) {
	t->id = i;
	strcpy(t->nome, n);
	t->sala = s;
	t->numero_de_alunos = 0;
}

void adicionar_aluno(t_turma *t, t_aluno *a) {
	if (t->numero_de_alunos < TURMA_SIZE) {
		t->alunos[t->numero_de_alunos] = a;
		t->numero_de_alunos++;
	} 
    else {
		printf("Turma cheia!");
	}
}

void imprimir_aluno(t_aluno *a) {
	printf("-------------------------------------------\n");
	printf("Aluno: %s\n", a->nome);
	printf("Matricula: %d\n", a->matricula);
	printf("CRA: %lf\n", a->cra);
	printf("-------------------------------------------\n");
}

void imprimir_turma(t_turma *t) {
	printf("*******************************************\n");
	printf("Turma: %s", t->nome);
	printf("Id: %d\n", t->id);
	printf("Sala: %d\n", t->sala);
	for (int i=0; i<t->numero_de_alunos; i++) {
		imprimir_aluno(t->alunos[i]);
	}
	printf("******************************************\n");
}

int main(void) {
	int turma_id, turma_sala;
	char turma_nome[NOME_TURMA_SIZE];
	t_turma t1;
	int qtd_alunos = 0;

	printf("Digite o id da turma: ");
	scanf("%d", &turma_id);
	printf("Digite a sala da turma: ");
	scanf("%d%*c", &turma_sala);
	printf("Digite o nome da turma: ");
	fgets(turma_nome, NOME_TURMA_SIZE, stdin);

	preenche_turma(&t1, turma_id, turma_nome, turma_sala);

	printf("Digite a quantidade de alunos a inserir: ");
	scanf("%d", &qtd_alunos);

	if (qtd_alunos > TURMA_SIZE) {
		printf("Tamanho maior que o limite: %d\n", qtd_alunos);
		printf("Usando tamanho: %d\n", TURMA_SIZE);
		qtd_alunos = TURMA_SIZE;
	}

	for (int i=0; i<qtd_alunos; i++) {
		int aluno_matricula;
		double aluno_cra;
		char aluno_nome[NOME_ALUNO_SIZE];
		t_aluno *a1;
		a1 = (t_aluno*) malloc(sizeof(t_aluno));
		printf("Digite a matricula do aluno[%d]: ", i);
		scanf("%d", &aluno_matricula);
		printf("Digite o CRA do aluno[%d]: ", i);
		scanf("%lf%*c", &aluno_cra);
		printf("Digite o nome do aluno[%d]: ", i);
		fgets(aluno_nome, NOME_ALUNO_SIZE, stdin);
		preenche_aluno(a1, aluno_matricula, aluno_nome, aluno_cra);
		adicionar_aluno(&t1, a1);
	}

	imprimir_turma(&t1);

	return 0;
}

