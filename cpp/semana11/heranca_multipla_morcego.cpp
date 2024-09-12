#include <iostream>

using std::cout;
using std::endl;

class Animal {
	int age;
public:
	Animal(int a): age(a){
		cout << "animal(" << age << ")" << endl;
	}

    int get_age() const {
        return age;
    }

    void set_age(int a) {
        age = a;
    }
};

class Mammal : virtual public Animal {
    int coat;
public:
    Mammal(int a, int c): Animal(a), coat(c) {
        cout << "Mammal(" << a << ", " << coat << ")" << endl;
    }

    int get_coat() const {
        return coat;
    }

    void set_coat(int c) {
        coat = c;
    } 
};

class Bird : virtual public Animal {
	double wingspan;
public:
	Bird(int a, double w): Animal(a), wingspan(w) {
		cout << "bird(" << a << ",";
		cout << wingspan << ")" << endl;
	}

	double get_wingspan() const {
		return wingspan;
	}

    void set_wingspan(double w) {
        wingspan = w;
    }
};

class Bat : public Mammal, public Bird {
    bool hematophagous;
public:
    Bat(int a, int c, double w, bool h): Animal(a), Mammal(a, c), Bird(a, w), hematophagous(h) {
        cout << "Bat(" << a << ", " << c << ", " << w << ", " << hematophagous << ")" << endl;
    }

    void print_info() {
        cout << "Bat(" << get_age() << ", " << get_coat() << ", " << get_wingspan() << ", " << hematophagous << ")" << endl;
    }
};

class Vampire : public Bat {
    Vampire(int a, int c, double w, bool h): Animal(a), Bat(a, c, w, h) {
        cout << "Vampire(" << a << ", " << c << ", " << w << ", " << h << ")" << endl;
    }
};

int main(void) {
	Vampire v1(1, 5, 10.5, false);
	
    Animal* pa1 = &v1;
	Mammal* pm1 = &v1;
	Bird *pb1 = &v1;
		
    cout << pa1->get_age() << endl << endl;
    
    cout << pm1->get_age() << endl;
    cout << pm1->get_coat() << endl << endl;
    
    cout << pb1->get_age() << endl;
    cout << pb1->get_wingspan() << endl;
    
    //b1.print_info();
		
	return 0;
}