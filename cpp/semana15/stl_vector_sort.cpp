#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

class aluno {
	string nome;
	double cra;
public:
	aluno(const string &n, double c) : nome(n), cra(c) {}

	double get_cra() { 
        return cra; 
    }

	string get_nome() { 
        return nome; 
    }

	void print_info() {
		cout << "(" << nome << ", " << cra << ")" << endl;
	}

	friend bool operator<(const aluno &a, const aluno &b) {
		return (a.cra < b.cra);
	}
};

bool compara_aluno(aluno &a, aluno &b) {
	return (a.get_cra() < b.get_cra());
}

int main() {
	vector<aluno> turma;
	vector<int> numbers = {3, 5, 6, 2, 1, 4};

	sort(numbers.begin(), numbers.end());

	for (auto n : numbers) {
		cout << n << " ";
	}

	cout << endl;

	turma.push_back(aluno("Ana", 9.5));
	turma.push_back(aluno("Bob", 7.5));
	turma.push_back(aluno("Alice", 10.0));
	turma.push_back(aluno("Joe", 8.6));

    //	sort(turma.begin(), turma.end(), compara_aluno);
	sort(turma.begin(), turma.end());

	for (auto a : turma) {
		a.print_info();
	}

	cout << endl;

	return 0;
}