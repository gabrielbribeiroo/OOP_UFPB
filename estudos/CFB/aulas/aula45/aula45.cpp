#include "aviao.h"

int main(void) {
    aviao *av1 = new aviao(3);
    aviao *av2 = new aviao(1);
    aviao *av3 = new aviao(2);

    av1->print_info();
    av2->print_info();
    av3->print_info();

    return 0;
}
