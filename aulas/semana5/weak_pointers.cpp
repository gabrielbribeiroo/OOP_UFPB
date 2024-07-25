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

int main() {
	std::shared_ptr<coisa> ptr1 = std::make_shared<coisa>(997);
	std::weak_ptr<coisa> wptr = ptr1;

	std::cout << "Contagem de refs: " << ptr1.use_count() << std::endl;

	ptr1->fazer_algo();

	if (auto shared_ptr = wptr.lock()) {
		shared_ptr->fazer_algo();
	} 
    else {
		std::cout << "Recurso nao mais disponivel" << std::endl;
	}

	return 0;
}

