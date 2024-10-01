#include <iostream>

using std::cout;
using std::endl;

#define VECTOR_SIZE 5

class int_vector {
	int *data;
	int size;
public:
	int_vector(int s) {
		data = new int[s];
	}

	~int_vector() {
		delete[] data;
	}

	int get_size() {
		return size;
	}

	int &operator[](int index) {
		if ((index >= 0) && (index < size)) {
			return data[index];
		} 
        else {
			std::cerr << "Indice errado!" << endl;
			exit(EXIT_FAILURE);
		}
	}
};

int main() {
	int_vector iv(VECTOR_SIZE);

	for (int i=0; i<VECTOR_SIZE; i++) {
		cout << "[" << i << "] = " << (i+1)*10 << endl;
		iv[i] = (i+1)*10;
	}

	for (int i=0; i<VECTOR_SIZE; i++) {
		cout << "[" << i << "] " << iv[i] << endl;
	}

	return 0;
}
