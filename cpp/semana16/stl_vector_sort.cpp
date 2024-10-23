#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::partial_sort; // C++17

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
};

bool compara_aluno(aluno &a, aluno &b) {
	return (a.get_idade() < b.get_idade());
}

int main() {
	vector<aluno> turma;
	vector<int> numbers = { 3, 5, 6, 2, 1, 4 };

	sort(numbers.begin(), numbers.end());

	for (auto n : numbers) {
		cout << n << " ";
	}

	cout << endl;

	turma.push_back(aluno("Ana", 9.5, 20));
	turma.push_back(aluno("Bob", 7.5, 22));
	turma.push_back(aluno("Alice", 10.0, 21));
	turma.push_back(aluno("Joe", 8.6, 19));

	vector<aluno>::iterator it = turma.begin();

    //	partial_sort(turma.begin(), it+2, turma.end(), compara_aluno);
	sort(turma.begin(), turma.end());

	cout << "Turma ordenada pela idade: " << endl;

	for (auto a : turma) {
		a.print_info();
	}

	cout << endl;

	sort(turma.begin(), turma.end());

	cout << "Turma ordenada pelo CRA: " << endl;

	for (auto a: turma) {
		a.print_info();
	}

	cout << endl;

	return 0;
}