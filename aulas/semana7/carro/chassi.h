#ifndef CHASSI_H
#define CHASSI_H

#include <string>

using std::string;

class chassi {
	string material;
	string serial;
public:
	chassi(const string& m, const string& s);
	~chassi();

	void suportar();
};

#endif //CHASSI_H
