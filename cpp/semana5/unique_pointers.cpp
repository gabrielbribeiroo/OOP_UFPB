#include <iostream>
#include <memory>

class coisa {
	int att;
public:
	coisa(int i): att(i) { }
	void fazer_algo() {
		std::cout << "coisa::fazer_algo(" << att << ")" << std::endl;
	}
};

int main(void) {
    std::unique_ptr<coisa> ptr = std::make_unique<coisa>(999);

	ptr->fazer_algo();

	std::unique_ptr<coisa> ptr2 = std::move(ptr);

	//std::unique_ptr<coisa> ptr2 = ptr; //IMPOSSIVEL

	ptr2->fazer_algo();

	//ptr->fazer_algo(); //ERRO! ptr agora esta vazio
    
    return 0;
}