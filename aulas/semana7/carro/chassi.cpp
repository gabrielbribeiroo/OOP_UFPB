#include "chassi.h"
#include <iostream>

using std::cout;
using std::endl;

chassi::chassi(const string& m, const string& s):
			material(m), serial(s) {
	cout << "chassi(" << material << ", ";
	cout << serial << ")" << endl;
}

chassi::~chassi() {
	cout << "~chassi(" << serial << ")" << endl;
}

void chassi::suportar() {
	cout << "chassi(" << serial << ").suportar()";
	cout << endl;
}
