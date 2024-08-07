#include <iostream>
#include "carro.h"

using std::cout;
using std::cin;
using std::endl;

int main(void) {

    /*
	auto motor1 = std::make_unique<motor>("V8", 2.0);
	auto roda1 = std::make_unique<roda>(15);
	auto chassi1 = std::make_unique<chassi>("Aço", "234A");

	carro carro1("AA123", std::move(motor1), std::move(roda1), std::move(chassi1));

	//motor1->ligar(); //erro! - ponteiro nao aponta mais
    */

	cout << "Criando carro1: " << endl;
	carro carro1("AA123",
		     std::make_unique<motor>("V8", 2.0),
		     std::make_unique<roda>(15),
		     std::make_unique<chassi>("Aço", "234A"));
	carro1.ligar();

	cout << "Criando carro2: " << endl;
	carro carro2("AB987",
		     std::make_unique<motor>("V12", 3.0),
		     std::make_unique<roda>(14),
		     std::make_unique<chassi>("Aço", "754B"));
	carro2.ligar();

	cout << "Trocar motores e ligar os dois" << endl;

	auto motor_removido_1 = carro1.remove_motor();
	auto motor_removido_2 = carro2.remove_motor();

	carro1.set_motor(std::move(motor_removido_2));
	carro2.set_motor(std::move(motor_removido_1));

	cout << "Ligando carro1 e carro2" << endl;
	carro1.ligar();
	carro2.ligar();

	return 0;
}