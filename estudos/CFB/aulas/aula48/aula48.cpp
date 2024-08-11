#include "classes.h"

int main() {
    base1 *obj1 = new base1();
    base2 *obj2 = new base2();
    CFB *obj3 = new CFB();

    obj1->print_base1();
    obj2->print_base2();
    obj3->print_base1();
    obj3->print_base2();
    
    return 0;
}