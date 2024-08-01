#include "carro.h"

int main(void) {
	auto motor1 = std::make_unique<motor>("V8", 2.0);
	auto roda1 = std::make_unique<roda>(15);
	auto chassi1 = std::make_unique<chassi>("Aço", "234A");

	carro carro1("AA123", std::move(motor1), std::move(roda1), std::move(chassi1));

	carro1.ligar();

	return 0;
}
