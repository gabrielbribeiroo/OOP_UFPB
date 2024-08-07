#ifndef MOTOR_H
#define MOTOR_H

#include <string>

using std::string;

class motor {
	string modelo;
	double cilindradas;
public:
	motor(const string &m, double c);
	~motor();
	void ligar();
};

#endif //MOTOR_H