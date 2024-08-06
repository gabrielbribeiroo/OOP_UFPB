#include "carro.h"
#include <iostream>

using std::cout;
using std::endl;

carro::carro(const string& p, std::unique_ptr<motor> m,
                std::unique_ptr<roda> r,
                std::unique_ptr<chassi> c): placa(p),
					   carro_motor(std::move(m)),
					   carro_roda(std::move(r)),
					   carro_chassi(std::move(c)) {
	cout << "carro(" << placa << ") " << endl;
}

carro::~carro() {
	cout << "~carro(" << placa << ") " << endl;
}

void carro::ligar() {
	cout << "carro::ligar()" << endl;
	if (carro_motor) carro_motor->ligar();
	if (carro_roda) carro_roda->girar();
	if (carro_chassi) carro_chassi->suportar();
	cout << "vrum vrum - carro ligado!" << endl;
}

void carro::set_motor(std::unique_ptr<motor> novo_motor) {
	carro_motor = std::move(novo_motor);
}

std::unique_ptr<motor> carro::remove_motor() {
	return std::move(carro_motor);
}
