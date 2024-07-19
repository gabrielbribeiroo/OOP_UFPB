#include <iostream>

class ponto2d {
    int x;
    int y;

    public:
        ponto2d(int xx, int yy) {
            x = xx;
            y = yy;
        }
        ponto2d() {
            x = 0;
            y = 0;
        }
        ~ponto2d() {
            std::cout << "destrutor ponto2d ";
            std::cout << "x = " << x << ", ";
            std::cout << "y = " << y;
            std::cout << std::endl;
        }
        int get_x() { 
            return x; 
        }
        void set_x(int xx) { 
            x = xx; 
        }
        int get_y() { 
            return y; 
        }
        void set_y(int yy) { 
            y = yy; 
        }
        void print_info() {
            std::cout << "ponto2d(";
            std::cout << x << ", ";
            std::cout << y << ")";
            std::cout << std::endl;
        }
};

int main(void) {
    ponto2d p1(10, 20);
    ponto2d p2;
    ponto2d *pp2;
    ponto2d *pp3;

    pp2 = &p2;

    pp2->set_x(100);
    pp2->set_y(200);

    pp3 = new ponto2d(1000, 2000);

    p1.print_info();
    p2.print_info();

    pp3->print_info();

    delete (pp3);
    // pp3 -> print_info(); LIXO DE MEMÓRIA
    // delete pp2; ERRO!

    return 0;
}
