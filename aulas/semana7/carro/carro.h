#ifndef CARRO_H
#define CARRO_H

#include <string>
#include <memory>
#include "motor.h"
#include "roda.h"
#include "chassi.h"

using std::string;

class carro {
	string placa;
	std::unique_ptr<motor> carro_motor;
	std::unique_ptr<chassi> carro_chassi;
	std::unique_ptr<roda> carro_roda;
public:
	carro(const string& p, std::unique_ptr<motor> m,
		std::unique_ptr<roda> r,
		std::unique_ptr<chassi> c);
	~carro();
	void ligar();
	void set_motor(std::unique_ptr<motor> nm);
	std::unique_ptr<motor> remove_motor();
};

#endif //CARRO_H
