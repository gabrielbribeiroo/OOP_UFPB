#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::sort;
using std::find;
using std::ostream;

class ponto2d {
	double x;
	double y;
public:
	ponto2d(double xx, double yy): x(xx), y(yy) {}

	double get_x() const { 
        return x; 
    }

	double get_y() const { 
        return y;
    }

	friend ostream &operator<<(ostream &out, const ponto2d &p) {
		out << "(" << p.x << ", " << p.y << ") ";
		return out;
	}

	friend bool operator<(const ponto2d &a, const ponto2d &b) {
		return ((a.x+a.y) < (b.x+b.y));
	}

	friend bool operator==(const ponto2d &a, const ponto2d &b) {
		return ((a.x == b.x) && (a.y == b.y));
	}
};

bool compara_ponto(ponto2d &a, ponto2d &b) {
	return ( (a.get_x() * a.get_y()) < (b.get_x() * b.get_y()) );
}

int main() {
	vector<ponto2d> v1 = { {1, 0.9}, {1.1, 3.7}, {4.5, 9.8}, {1, 1}, {5.1, 1.4} };

    list<ponto2d> v2 = { {4.1, 3.2}, {3.1, 5.7}, {8.4, 3.2}, {4.7, 6.3}, {6.1, 4.2} };

	sort(v1.begin(), v1.end());

	for (auto p : v1) {
		cout << p << endl;
	}

	cout << endl;

	sort(v1.begin(), v1.end(), compara_ponto);

	for (auto p : v1) {
		cout << p << endl;
	}

	double sn1, sn2;

	cout << "Digite um numero real: ";
	cin >> sn1;
	cout << "Digite outro numero real: ";
	cin >> sn2;

	ponto2d sp(sn1, sn2);

	vector<ponto2d>::iterator it_v;
	list<ponto2d>::iterator it_l;

	it_v = find(v1.begin(), v1.end(), sp);
	it_l = find(v2.begin(), v2.end(), sp);

	cout << "v1: " << endl;

	if (it_v == v1.end()) {
		cout << "Ponto " << sp << " nao encontrado!";
		cout << endl;
	} 
    else {
		cout << "Ponto " << sp << " encontrado!";
		cout << endl;
	}

	cout << "v2: " << endl;

    if (it_l == v2.end()) {
        cout << "Ponto " << sp << " nao encontrado!";
        cout << endl;
    } 
    else {
        cout << "Ponto " << sp << " encontrado!";
        cout << endl;
    }

	return 0;
}