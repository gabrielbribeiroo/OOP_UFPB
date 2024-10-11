#include <iostream>

using std::cout;
using std::endl;

namespace math {
	const double pi = 3.14;

	namespace functions {
		int sum(int a, int b) {
			return a+b;
		}

		int sub(int a, int b) {
			return a-b;
		}
	}
	namespace types {
		class imaginary_number {
			double real;
			double img;
		public:
			imaginary_number(double r, double i): real(r), img(i) {}
			void print_info() {
				cout << "(" << real << ", " << img << ")" << endl;
			}
		};
	}
}

using namespace math::functions;
namespace mtypes = math::types; // para o namespace math::types

int main() {
	int x, y, a, b;
	a = 10;
	b = 20;

	x = sum(a,b);
	y = sub(a,b);

	cout << "Resultado da soma: " << x << endl;
	cout << "Resultado da subtracao: " << y << endl;
	cout << "Valor de pi: " << math::pi << endl;

	mtypes::imaginary_number i(5,0.3);

	i.print_info();
}