#include "roda.h"
#include <iostream>

using std::cout;
using std::endl;

roda::roda(int a):aro(a) {
	cout << "roda(" << aro << ") " << endl;
}

roda::~roda() {
	cout << "~roda()" << endl;
}

void roda::girar() {
	cout << "roda(" << aro << ").girar()" << endl;
}
