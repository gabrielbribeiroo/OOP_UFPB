#include <iostream>
#include <random>

using std::cout;
using std::endl;

class Singleton {
    int var;
    static Singleton *instance;

    Singleton() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,10);
        var = dist6(rng);
        cout << "instancia criada!" << endl;
    }

    ~Singleton() {
        cout << "instancia finalizada!" << endl;
    }

public:
    static Singleton *get_instance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;        
    }

    void print_info() {
        cout << "singleton(" << var << ")" << endl;
    }

    static void destroy_instance() {
        delete instance;
        instance = nullptr;
    }
};

Singleton *Singleton::instance = nullptr;

int main() {
    Singleton *s1 = Singleton::get_instance();
    Singleton *s2 = Singleton::get_instance();

    s1->print_info();
    s2->print_info();

    if (s1==s2) {
        cout << "s1 e s2 apontam para a mesma instancia." << endl;
    }

    Singleton::destroy_instance();

    s1 = Singleton::get_instance();
	s2 = Singleton::get_instance();

	s1->print_info();
    s2->print_info();

    if (s1==s2) {
        cout << "s1 e s2 apontam para a mesma instancia" << endl;
    }

    return 0;
}