#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int x;

	cout << "Digite um numero: ";
	cin >> x;

	try {
		if (x % 2) {
			cout << "Tudo ok" << endl;
		} 
        else {
			if (x > 10) {
				throw (((double)(0.5)*x)+(0.1));
			}
			throw x; // Desvio
			cout << "Nunca vai aparecer!" << endl;
		}
	} 
    catch (int e) {
		cout << "Excecao (int) capturada! Valor: " << e << endl;
	} 
    catch (double e) {
		cout << "Excecao (double) capturada! Valor: " << e << endl;
	}

	return 0;
}
