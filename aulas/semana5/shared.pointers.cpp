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
    std::shared_ptr<coisa> ptr1 = std::make_shared<coisa>(998);

	{
		std::shared_ptr<coisa> ptr2 = ptr1;
		std::cout << "Contagem de refs: " << ptr1.use_count() << std::endl;
	}

	std::cout << "Contagem de refs (pos escopo): " << ptr1.use_count() << std::endl;
    
    return 0;
}