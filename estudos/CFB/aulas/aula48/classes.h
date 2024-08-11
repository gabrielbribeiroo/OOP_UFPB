#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

using std::cout;
using std::endl;

class base1 {
public:
    void print_base1();
};

void base1::print_base1() {
    cout << "print class base1" << endl;  
} 

class base2 {
public:
    void print_base2();
};

void base2::print_base2() {
    cout << "print class base2" << endl;
}

// A classe CFB herda características de base1 e de base2 (herança múltipla)
class CFB: public base1, public base2 {
};

#endif // CLASSES_H