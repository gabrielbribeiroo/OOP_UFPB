#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Device {
public:
    void power_on() const {
        cout << "Device on" << endl;
    }
};

class Printer : public virtual Device {

};

class Scanner : public virtual Device {

};

class Multifuncional : public Printer, public Scanner {

};

int main() {
    Multifuncional m1;

    m1.power_on();

    return 0;
}