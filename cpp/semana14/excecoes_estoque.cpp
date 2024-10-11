#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::exception;
using std::ostream;
using std::srand;
using std::rand;
using std::time;

class produto_nao_encontrado : public exception {
public:
	const char *what() const noexcept {
		return "produto nao encontrado!";
	}
};

class quantidade_insuficiente : public exception {
public:
	const char *what() const noexcept {
		return "quantidade insuficiente!";
	}
};

class quantidade_invalida : public exception {
public:
	const char *what() const noexcept {
		return "quantidade invalida!";
	}
};

class produto {
	int id;
	string nome;
	int qtd;
	double preco;
public:
	produto(int i, const string &n, int q, double p): id(i), nome(n), qtd(q), preco(p) {}

	int get_qtd() const {
		return qtd;
	}

	void set_qtd(int q) {
		qtd = q;
	}

	int get_id() const {
		return id;
	}

	const string &get_nome() const {
		return nome;
	}

	double get_preco() const {
		return preco;
	}
};

class estoque {
	vector<produto> produtos;
public:
	void adicionar_produto(const produto &p) noexcept {
		produtos.push_back(p);
		cout << "[estoque] Produto: " << p.get_nome();
		cout << " adicionado ao estoque!" << endl;
	}

	void remover_produto(int search_id) {
		for (auto it = produtos.begin(); it != produtos.end(); ++it) {
			if (it->get_id() == search_id) {
				cout << "[estoque] Produto: " << it->get_nome();
				cout << "(" << it->get_id() << ") ";
				cout << "foi removido do estoque!" << endl;
				produtos.erase(it);
				return;
			}
		}
		throw produto_nao_encontrado();
	}

	void atualizar_quantidade(int search_id, int q) {
		if (q <= 0) {
			throw quantidade_invalida();
		}

		for (auto &p : produtos) {
			if (p.get_id() == search_id) {
				if (q > p.get_qtd()) {
					throw quantidade_insuficiente();
				}
				p.set_qtd(p.get_qtd() - q); //atualiza qtd
				cout << "[estoque] Produto " << p.get_nome();
				cout << " com estoque atualizado para: ";
				cout << p.get_qtd() << endl;
				return;
			}
		}

		throw produto_nao_encontrado();
	}

	void consultar_produto(int search_id) {
		for (auto& p : produtos) {
			if (p.get_id() == search_id) {
				cout << "[estoque] Produto: " << p.get_nome();
				cout << " (" << p.get_id() << ") " << endl;
				cout << "Preco: " << p.get_preco() << endl;
				cout << "Estoque: " << p.get_qtd() << endl;
				cout << "-------------------" << endl;
				return;
			}
		}
		throw produto_nao_encontrado();
	}

	friend ostream &operator<<(ostream &os, const estoque &e) {
		os << "[estoque] Estoque geral: " << endl;
		os << "-------------------" << endl;
		for (auto &p : e.produtos) {
                                os << "Produto: " << p.get_nome();
                                os << " (" << p.get_id() << ") " << endl;
                                os << "Preco: " << p.get_preco() << endl;
                                os << "Estoque: " << p.get_qtd() << endl;
                                os << "-------------------" << endl;
		}

		return os;
	}
};

void lanca_excecao_desconhecida() {
	srand(time(nullptr));

	int rand_num = rand() % 3;

	switch(rand_num) {
		case 0: {
			throw 1000;
		}
		case 1: {
			throw 0.50;
		}
		case 2: {
			throw exception();
		}
	}
}

int main() {
	estoque estoque_geral;

	try {
		estoque_geral.adicionar_produto(produto(1, "Caneta", 100, 3.50));
		estoque_geral.adicionar_produto(produto(2, "Caderno", 50, 15.40));
		estoque_geral.adicionar_produto(produto(3, "Borracha", 80, 2.20));
		estoque_geral.adicionar_produto(produto(4, "Lapis", 120, 3.00));

		cout << estoque_geral;
		//estoque_geral.atualizar_quantidade(1, -20);  //1

		estoque_geral.atualizar_quantidade(3, 40);     //2
		//estoque_geral.atualizar_quantidade(1, 110);  //3

		estoque_geral.atualizar_quantidade(2, 20);     //4
		//estoque_geral.atualizar_quantidade(12, 100); //5

		estoque_geral.atualizar_quantidade(2, 10);     //6
		//estoque_geral.remover_produto(10);           //7

		estoque_geral.remover_produto(4);              //8
		//estoque_geral.consultar_produto(11);         //9

		estoque_geral.consultar_produto(2);            //10
		lanca_excecao_desconhecida();                  //11
	}
	catch (const produto_nao_encontrado &e) {
		cerr << "!!!!!!!!!!!!!!!" << endl;
		cerr << e.what() << endl;
		cerr << "!!!!!!!!!!!!!!!" << endl;
	}
	catch (const quantidade_invalida &e) {
		cerr << "!!!!!!!!!!!!!!!" << endl;
		cerr << e.what() << endl;
		cerr << "!!!!!!!!!!!!!!!" << endl;
	}
	catch (const quantidade_insuficiente e) {
		cerr << "!!!!!!!!!!!!!!!" << endl;
		cerr << e.what() << endl;
		cerr << "!!!!!!!!!!!!!!!" << endl;
	}
	catch (...) {
		cerr << "!!!!!!!!!!!!!!!!" << endl;
		cerr << "Erro inesperado!" << endl;
		cerr << "!!!!!!!!!!!!!!!!" << endl;
	}

	cout << estoque_geral << endl;

	return 0;
}
