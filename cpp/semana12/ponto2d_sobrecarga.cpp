#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ponto2d {
    int x, y;
public:
    // Construtor com argumentos padrão 
    ponto2d(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }

    // Construtor de cópia
    ponto2d(const ponto2d &outro) {
        x = outro.x;
		y = outro.y;
    }

    // Destrutor
    ~ponto2d() {
        cout << "ponto2d(" << x << ", " << y << ")" << endl;
    }

    int get_x() {
		return x;
	}

	void set_x(int xx) {
		x = xx;
	}

	int get_y() {
		return y;
	}

	void set_y(int yy) {
		y = yy;
	}

	void print_info() {
		cout << "ponto2d(" << x << ", " << y << ")" << endl;
	}

    ponto2d operator+(ponto2d &outro) {
        ponto2d result(x + outro.x, y + outro.y);
        return result;
    }

    ponto2d operator+(int i) {
        ponto2d result(x + i, y + i);
        return result;
    }

    friend ponto2d operator+(int i, ponto2d p) {
        ponto2d result(p.x + i, p.y + i);
        return result;
    }

    friend ponto2d operator-(ponto2d a, ponto2d b) {
        ponto2d result(a.x - b.x, a.y - b.y);
        return result;
    }

    ponto2d operator*(ponto2d outro) {
        ponto2d result(x * outro.x, y * outro.y);
        return result;
    }

    ponto2d operator*(int i) {
        ponto2d result(x * i, y * i);
        return result;
    }

    friend ponto2d operator*(int i, ponto2d p) {
        ponto2d result(p.x * i, p.y * i);
        return result;
    }

    ponto2d operator/(ponto2d outro) {
        ponto2d result(x / outro.x, y / outro.y);
        return result;
    }

    ponto2d operator/(int i) {
        ponto2d result(x / i, y / i);
        return result;
    }

    // Versão pré-fixada
    ponto2d &operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Versão pós-fixada
    ponto2d operator++(int) {
        ponto2d temp = *this;
		++x;
		++y;
		return temp;
    }
};

int main() {
    ponto2d p1(10, 20);
	ponto2d p2(30, 40);

	//ponto2d p3 = p2.operator+(p1);
	ponto2d p3 = p2 + p1;

	ponto2d p4 = 10 + p3;
	//ponto2d p4 = operator+(10, p3);

	ponto2d p5 = p4 - p3;
	//ponto2d p5 = operator-(p4, p3);

	ponto2d p6 = p1 * p2;
	//ponto2d p6 = p1.operator*(p2);

	ponto2d p7 = p6 * 10;
	//ponto2d p7 = p6.operator*(10);

	ponto2d p8 = 10 * p1;
	//ponto2d p8 = operator*(10, p1);

	ponto2d p9 = p8 / p7;
	//ponto2d p9 = p8.operator/(p7);

	++p1;

	ponto2d p10 = p9++;

	p1.print_info();
	p2.print_info();
	p3.print_info();
	p4.print_info();
	p5.print_info();
	p6.print_info();
	p7.print_info();
	p8.print_info();
	p9.print_info();
	p10.print_info();
    return 0;
}