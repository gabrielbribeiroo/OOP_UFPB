#include <stdio.h>   // Biblioteca padrão para funções de entrada e saída
#include <stdlib.h>  // Biblioteca padrão para funções de alocação de memória, conversão de tipos, etc.

#define TAM_NOME 40  // Define o tamanho máximo do nome do aluno
#define ARG_COUNT 2  // Define o número esperado de argumentos na linha de comando

/*
 * MINI SIGAA
 * Este código é um exemplo de como implementar estruturas e funções em C para representar e manipular alunos e turmas.
 */

// Estrutura para representar um aluno
typedef struct {
	char nome[TAM_NOME];  // Nome do aluno
	int matricula;        // Número de matrícula do aluno
	float cra;            // Coeficiente de Rendimento Acadêmico (CRA) do aluno
} t_aluno;

// Estrutura para representar uma turma
typedef struct {
	t_aluno *alunos;  // Ponteiro para um array de alunos
	int tam_turma;    // Tamanho da turma (número de alunos)
	int sala;         // Número da sala de aula
} t_turma;

// Função para cadastrar um aluno
void cadastra_aluno(t_aluno *a) {
	char c;
	printf("Digite o nome do aluno: ");
	scanf("%[^\n]", a->nome);  // Lê o nome do aluno
	printf("Digite a matricula do aluno: ");
	scanf("%d", &a->matricula);  // Lê a matrícula do aluno
	printf("Digite o CRA do aluno: ");
	scanf("%f", &a->cra);  // Lê o CRA do aluno
	scanf("%c", &c); // ATS: consome o caractere '\n' remanescente
}

// Função para exibir informações de um aluno
void exibe_aluno(t_aluno *a) {
	printf("Nome: %s\n", a->nome);  // Exibe o nome do aluno
	printf("Matricula: %d\n", a->matricula);  // Exibe a matrícula do aluno
	printf("CRA: %f\n", a->cra);  // Exibe o CRA do aluno
}

// Função para cadastrar uma turma
void cadastra_turma(t_turma *t, int tam) {
	printf("Cadastrando turma com %d alunos...\n", tam);
	t->alunos = (t_aluno*) malloc(sizeof(t_aluno) * tam);  // Aloca memória para os alunos
	t->tam_turma = tam;  // Define o tamanho da turma
	for (int i = 0; i < tam; i++) {
		cadastra_aluno(&t->alunos[i]);  // Cadastra cada aluno na turma
	}

	printf("Digite o numero da sala: ");
	scanf("%d", &t->sala);  // Lê o número da sala de aula
}

// Função para exibir informações de uma turma
void exibe_turma(t_turma* t) {
	printf("Sala: %d\n", t->sala);  // Exibe o número da sala de aula
	for (int i = 0; i < t->tam_turma; i++) {
		exibe_aluno(&t->alunos[i]);  // Exibe as informações de cada aluno na turma
	}
}

// Função principal
// Recebe o número de alunos da turma como argumento na linha de comando
// Cadastra a turma e exibe as informações dos alunos
int main(int argc, char** argv) {
	t_turma turma;
	int tam_turma = 0;
	
	// Verifica se o número de argumentos passados na linha de comando é o esperado
	if (argc != ARG_COUNT) {
		printf("Use: %s <NUMERO_DE_ALUNOS>\n", argv[0]);  // Informa o uso correto do programa
		exit(0);  // Termina o programa se o número de argumentos estiver incorreto
	} 
    else {
		tam_turma = atoi(argv[1]);  // Converte o argumento da linha de comando para inteiro
		cadastra_turma(&turma, tam_turma);  // Cadastra a turma
		exibe_turma(&turma);  // Exibe as informações da turma
	}

	// Libera a memória alocada para os alunos da turma
	for (int i = 0; i < tam_turma; i++) {
		free(&turma.alunos[i]);  // Libera a memória alocada para cada aluno
	}

	return 0;
}