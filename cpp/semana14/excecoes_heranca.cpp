#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class ioexception {
public:
	virtual string message() = 0;
};

class input_exception : public ioexception {
public:
	string message() {
		return "INPUT";
	}
};

class output_exception : public ioexception {
public:
	string message() {
		return "OUTPUT";
	}
};

class other_exception : public ioexception {
public:
	string message() {
		return "OTHER";
	}
};

void funcao() noexcept {
	cout << "noexcept funcao()" << endl;
}

int main(void) {
	int num;

	cout << "Digite um numero: ";
	cin >> num;

	try {
		funcao();
		if (num == 10) {
			throw new input_exception();
		} 
        else if (num == 20) {
			throw new output_exception();
		} 
        else if (num == 30) {
			throw new other_exception();
		}
		cout << "Tudo ok!" << endl;
	} 
    catch (input_exception *e) {
		cout << "Capturei excecao de input: " << e->message() << endl;
	} 
    /*catch (output_exception* e) {
		cout << "Capturei excecao de output: " << e->message() << endl;
	}*/
	catch (ioexception *e) {
		cout << "Excecao capturada: " << e->message() << endl;
	}

	return 0;
}