#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_STR_SIZE 50
#define TITLE_STR_SIZE 30
#define SCHEDULE_STR_SIZE 20
#define ROOM_STR_SIZE 20
#define MAX_STUDENTS 30

// Define a estrutura para representar um estudante
typedef struct {
    char name[NAME_STR_SIZE]; // Nome do estudante
    int registration; // Matrícula do estudante
    float CRA; // Coeficiente de Rendimento Acadêmico
    int age; // Idade do estudante
} t_student;

// Define a estrutura para representar um professor
typedef struct {
    char name[NAME_STR_SIZE]; // Nome do professor
    int SIAPE; // Número de identificação do professor
    int age; // Idade do professor
    char title[TITLE_STR_SIZE]; // Titulação do professor
} t_teacher;

// Define a estrutura para representar uma turma
typedef struct {
    char name[NAME_STR_SIZE]; // Nome da turma
    char schedule[SCHEDULE_STR_SIZE]; // Horário da turma
    char room[ROOM_STR_SIZE]; // Sala da turma
    t_student *students[MAX_STUDENTS];  // Array de ponteiros para alunos
    int num_students; // Número de alunos na turma
    t_teacher* teacher; // Ponteiro para um professor
} t_class;

// Função para criar um novo aluno
t_student* create_student(char* name, int registration, float CRA, int age) {
    t_student* new_student = (t_student*)malloc(sizeof(t_student)); // Aloca memória
    if (new_student == NULL) { // Verifica se a alocação foi bem sucedida
        // Se não foi, exibe mensagem de erro e encerra o programa
        printf("Erro ao alocar memória para o aluno.\n"); 
        exit(1); 
    }
    // Copia os valores passados como argumento para a estrutura do aluno
    strcpy(new_student->name, name);
    new_student->registration = registration;
    new_student->CRA = CRA;
    new_student->age = age;
    return new_student; // Retorna o ponteiro para o aluno criado
}

// Função para criar um novo professor
t_teacher* create_teacher(char* name, int SIAPE, int age, char* title) {
    t_teacher* new_teacher = (t_teacher*)malloc(sizeof(t_teacher)); // Aloca memória
    // Verifica se a alocação foi bem sucedida
    if (new_teacher == NULL) {
        // Se não foi, exibe mensagem de erro e encerra o programa
        printf("Erro ao alocar memória para o professor.\n");
        exit(1);
    }
    // Copia os valores passados como argumento para a estrutura do professor
    strcpy(new_teacher->name, name);
    new_teacher->SIAPE = SIAPE;
    new_teacher->age = age;
    strcpy(new_teacher->title, title);
    return new_teacher;
}

// Função para criar uma nova turma
t_class* create_class(char* name, char* schedule, char* room) {
    t_class* new_class = (t_class*)malloc(sizeof(t_class)); // Aloca memória
    // Verifica se a alocação foi bem sucedida
    if (new_class == NULL) {
        // Se não foi, exibe mensagem de erro e encerra o programa
        printf("Erro ao alocar memória para a turma.\n");
        exit(1);
    }
    // Copia os valores passados como argumento para a estrutura da turma
    strcpy(new_class->name, name);
    strcpy(new_class->schedule, schedule);
    strcpy(new_class->room, room);
    new_class->num_students = 0;
    return new_class;
}

// Função para cadastrar um aluno em uma turma
int register_student_to_class(t_class* class, t_student* student) {
    // Verifica se a turma já atingiu o número máximo de alunos
    if (class->num_students < MAX_STUDENTS) {
        // Adiciona o aluno ao array de alunos da turma
        class->students[class->num_students] = student;
        // Incrementa o número de alunos na turma
        class->num_students++;
        // Retorna o número de alunos na turma
        return class->num_students;
    } else {
        // Se a turma já atingiu o número máximo de alunos, exibe mensagem de erro
        printf("A turma já atingiu o número máximo de alunos.\n");
        // Retorna -1 para indicar que não foi possível adicionar o aluno
        return -1;
    }
}

// Função para cadastrar um professor em uma turma
void register_teacher_to_class(t_class* class, t_teacher* teacher) {
    // Atribui o ponteiro para o professor passado como argumento à turma
    class->teacher = teacher;
}

// Função para exibir informações de um aluno
void display_student(t_student* student) {
    printf("--------------------\n");
    printf("Nome: %s\n", student->name);
    printf("Matricula: %d\n", student->registration);
    printf("CRA: %.2f\n", student->CRA);
    printf("Idade: %d\n", student->age);
    printf("--------------------\n");
}

// Função para exibir informações de um professor
void display_teacher(t_teacher* teacher) {
    printf("Nome: %s\n", teacher->name);
    printf("SIAPE: %d\n", teacher->SIAPE);
    printf("Idade: %d\n", teacher->age);
    printf("Titulacao: %s\n", teacher->title);
}

// Função para exibir informações de uma turma
void display_class(t_class* class) {
    printf("================================\n");
    printf("Nome da Turma: %s\n", class->name);
    printf("Horario: %s\n", class->schedule);
    printf("Sala: %s\n", class->room);
    printf("Professor: \n");
    display_teacher(class->teacher);
    printf("Alunos: \n");
    for (int i = 0; i < class->num_students; i++) {
        display_student(class->students[i]);
    }
    printf("================================\n");
}

// Função principal para testar as funcionalidades
int main() {
    // Criação de alguns alunos
    t_student *student1 = create_student("Maria da Silva", 123, 9.5, 20);
    t_student *student2 = create_student("Jose Fernandes", 456, 8.7, 22);

    // Criação de dois professores
    t_teacher* teacher1 = create_teacher("Dr. Carlos", 789, 45, "PhD");
    t_teacher* teacher2 = create_teacher("Dra. Ana", 101, 40, "PhD");

    // Criação de duas turmas
    t_class* class1 = create_class("Algorithms", "08:00 - 10:00", "Sala 105");
    t_class* class2 = create_class("Data Structures", "10:00 - 12:00", "Sala 106");

    // Cadastro dos alunos nas turmas
    register_student_to_class(class1, student1);
    register_student_to_class(class1, student2);
    register_student_to_class(class2, student1);
    register_student_to_class(class2, student2);

    // Cadastro dos professores nas turmas
    register_teacher_to_class(class1, teacher1);
    register_teacher_to_class(class2, teacher2);

    // Exibição das informações da turma
    display_class(class1);
    display_class(class2);

    // Liberar a memória alocada
    free(student1);
    free(student2);
    free(teacher1);
    free(teacher2);
    free(class1);
    free(class2);

    return 0;
}
