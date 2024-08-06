#include "motor.h"
#include <iostream>

using std::cout;
using std::endl;

motor::motor(const string &m, double c): modelo(m), cilindradas(c) {
	cout << "motor(" << modelo << ")" << endl;
}

motor::~motor() {
	cout << "~motor(" << modelo << ")" << endl;

}

void motor::ligar() {
	cout << "motor.ligar(" << modelo << ", ";
	cout << cilindradas << ") " << endl;
}


