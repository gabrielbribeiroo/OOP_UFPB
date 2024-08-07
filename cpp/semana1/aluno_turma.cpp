#include <iostream>

#define PERSON_NAME_SIZE 40
#define DISC_NAME_SIZE 20
#define DISC_SIZE 30

class student {
	int code;
    char name[PERSON_NAME_SIZE];
    double gpa;
};

class discipline {
    int id;
    char name[DISC_NAME_SIZE];
    int room;
    student *students[DISC_SIZE];
    int number_of_students;
};

int main() {
	student s1;
	discipline d1;

	// d1.id = 10;
}
