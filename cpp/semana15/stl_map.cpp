#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
	map<string, double> medias = {{"Alice", 9.5}, {"Bob", 8.5}, {"Joe", 7.5}};

	medias["Joe"] = 8.2;
	medias["Ana"] = 9.2;

	// C++17
	for (const auto &[nome, media] : medias) {
		cout << nome << ": " << media << endl;
	}

	cout << endl;

	for (map<string, double>::iterator it = medias.begin(); it != medias.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}

	return 0;
}