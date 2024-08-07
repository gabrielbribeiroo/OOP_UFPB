#include <iostream>

class vetor {
    int *itens;
    int qtd;

    public:
        vetor(int q) {
            qtd = q;
            itens = (int *)malloc(q * sizeof(int));
            std::cout << "vetor(" << qtd << ")" << std::endl;
        }
        ~vetor() {
            free(itens);
            std::cout << "~vetor(" << qtd << ")" << std::endl;
        }
        int get_item(int i) {
            if (i < qtd) {
                return itens[i];
            } 
            else {
                return -1;
            }
        }
        void set_item(int i, int valor) {
            if (i < qtd) {
                itens[i] = valor;
            } 
            else {
                std::cout << "Erro" << std::endl;
            }
        }
};

int main(void) {
    vetor v1(10);
    vetor *pv2;

    pv2 = new vetor(5);

    v1.set_item(0, 1000);
    v1.set_item(1, 100);

    pv2->set_item(0, 5000);
    pv2->get_item(2, 2000);

    std::cout << v1.get_item(0) << std::endl;
    std::cout << pv2->get_item(2) << std::endl;

    delete (pv2);

    return 0;
}