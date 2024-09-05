/*
|-------------------------------------------------------------------------------------------------------------|
|      ENCAPSULAMENTO (ASC.)       |              HERANÇA              |          ENCAPSULAMENTO (DESC.)      |
|-------------------------------------------------------------------------------------------------------------|
|           public                 |                                   |               public                 |
|           protected              |              public               |              protected               |
|           private                |                                   |              ---------               |
|-------------------------------------------------------------------------------------------------------------|
|           public                 |                                   |              protected               |
|           protected              |             protected             |              protected               |
|           private                |                                   |              ---------               |
|-------------------------------------------------------------------------------------------------------------|
|           public                 |                                   |               private                |
|           protected              |              private              |               private                |
|           private                |                                   |              ---------               |
|-------------------------------------------------------------------------------------------------------------|
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person {
	string name;
	int age;
public:
	Person(const string &n, int a) : name(n), age(a) {} // Construtor

	string get_name() const { 
        return name; 
    }

	void set_name(const string &n) { 
        name = n;
    }

	int get_age() const { 
        return age; 
    }

	void set_age(int a) { 
        age = a;
    }

	virtual void print_info() {
		cout << "person(" << name << ", " << age << ") " << endl;
	}
};

class Client : public Person {
	string membership_type;
public:
	Client(const string &n, int a, const string &mt): Person(n, a), membership_type(mt) {} // Construtor

	string get_membership_type() const {
		return membership_type;
	}

	void set_membership_type(const string &mt) {
		membership_type = mt;
	}

	void print_info() {
		Person::print_info();
		cout << "client(" << membership_type << ")" << endl;
	}
};

class Employee : protected Person {
	double salary;
public:
	Employee(const string &n, int a, double s): Person(n,a), salary(s) {} // Construtor

	double get_salary() const { 
        return salary; 
    }

	void set_salary(double s) { 
        salary = s; 
    }

	void print_info_emp() {
		print_info();
		cout << "employee(" << salary << ")" << endl;
	}
};

class Trainer : private Person {
	string specialty;
public:
	Trainer(const string &n, int a, const string &s): Person(n,a), specialty(s) {} // Construtor

	string get_specialty() const { 
        return specialty;
    }

	void set_specialty(const string &s) {
		specialty = s;
	}

	void print_info_tra() {
		print_info();
		cout << "trainer(" << specialty << ")" << endl;
	}
};

int main() {
	Person* pp1;
	Client c1("John Doe", 35, "VIP");
	Employee e1("Mary Doe", 28, 4000);
	Trainer t1("Joseph Johnson", 18, "Developer");

/*
	c1.print_info();
	//e1.print_info(); - ERRO!
	//t1.print_info(); - ERRO!
	e1.print_info_emp();
	t1.print_info_tra();
*/
	pp1 = &c1;
	pp1->print_info();
};
