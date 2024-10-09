#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

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
    ~produto() {}

    int get_id() const {
        return id;
    }

    void set_id(int i) {
        id = i;
    }

    string get_nome() const {
        return nome;
    }

    void set_nome(const string &n) {
        nome = n;
    }

    int get_qtd() const {
        return qtd;
    }

    void set_qtd(int q) {
        qtd = q;
    }

    double get_preco() const {
        return preco;
    }

    void set_preco(double p) {
        preco = p;
    }
};

class estoque {
	vector<produto> produtos;
public:
	void adicionar_produto(const produto &p) noexcept {}

	void remover_produto(int i) {
		if (i < 0) {
			throw new quantidade_invalida();
		} 
        else if (i == 999) {
			throw new produto_nao_encontrado();
		}
	}

	void atualizar_quantidade(int i, int q) {
		if (i < 0) {
			throw new quantidade_invalida();
		} 
        else if (i == 888) {
			throw new quantidade_insuficiente();
		}
	}

	void consultar_produto(int i) {
		if (i == 555) {
			throw new produto_nao_encontrado();
		}
	}
};

int main() {
	estoque e;

	try {
		produto p(10, "sabao", 10, 5.5);
		e.adicionar_produto(p);
		e.remover_produto(-10);
		e.consultar_produto(555);
	} 
    catch(exception *e) {
		cout << e->what() << endl;
	}
}