#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::partial_sort; // C++17
using std::find;

class aluno {
	string nome;
	double cra;
	int idade;
public:
	aluno(const string &n, double c, int i) : nome(n), cra(c), idade(i) {}

	double get_cra() { 
        return cra; 
    }

	string get_nome() { 
        return nome; 
    }

	int get_idade() { 
        return idade; 
    }

	void print_info() {
		cout << "(" << nome << ", ";
		cout << cra << " ," << idade << ")" << endl;
	}

	friend bool operator<(const aluno &a, const aluno &b) {
		return (a.cra < b.cra);
	}

	friend bool operator==(const aluno &a, const aluno &b) {
		return ((a.idade == b.idade) && (a.nome == b.nome) && (a.cra == b.cra) );
	}
};

bool compara_aluno(aluno &a, aluno &b) {
	return (a.get_idade() < b.get_idade());
}

int main() {
	vector<aluno> turma;
	vector<int> numbers = { 3, 5, 6, 2, 1, 4 };
	int num_search;

	sort(numbers.begin(), numbers.end());

	for (auto n : numbers) {
		cout << n << " ";
	}

	cout << endl;

	cout << "Digite um numero: ";
	cin >> num_search;

	vector<int>::iterator it_num;

	it_num = find(numbers.begin(), numbers.end(), num_search);

	if (it_num == numbers.end()) {
		cout << "Numero " << num_search << " nao encontrado!";
		cout << endl;
	} 
    else {
		cout << "Numero " << *it_num << " encontrado!";
		cout << endl;
	}

	turma.push_back(aluno("Ana", 9.5, 20));
	turma.push_back(aluno("Bob", 7.5, 22));
	turma.push_back(aluno("Alice", 10.0, 21));
	turma.push_back(aluno("Joe", 8.6, 19));

	vector<aluno>::iterator it_tur = turma.begin();

    //	partial_sort(turma.begin(), it+2, turma.end(), compara_aluno);
	sort(turma.begin(), turma.end());

	for (auto al : turma) {
		al.print_info();
	}

	cout << endl;

	int id_search;
	double cr_search;
	string nm_search;

	cout << "Digite um nome: ";
	cin >> nm_search;
	cout << "Digite uma idade: ";
	cin >> id_search;
	cout << "Digite um CRA: ";
	cin >> cr_search;

	aluno a_search(nm_search, cr_search, id_search);

	vector<aluno>::iterator it_al;

	it_al = find(turma.begin(), turma.end(), a_search);

	if (it_al == turma.end()) {
		cout << "Aluno " << num_search;
		cout << " nao encontrado." << endl;
		a_search.print_info();
	} 
    else {
		cout << "Aluno encontrado!" << endl;
		(*it_al).print_info();
	}

	return 0;
}