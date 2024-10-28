#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

int main() {
    list<int> lst1; // Lista sem elementos
    list<int> lst2(10, 0); // Lista com 10 elementos 0
    list<int> lst3(lst2); // Lista igual a outra
    list<int> lst4 = {1, 2, 3, 4}; // Lista com elementos

    for (auto it=lst4.begin(); it != lst4.end(); it++) {
        cout << *it << "  ";
    }

    cout << endl;
    cout << "Tamanho: " << lst4.size() << endl;
    cout << "Capacidade maxima: " << lst4.max_size() << endl;
    cout << "Primeiro elemento: " << lst4.front() << endl;
    cout << "Ultimo elemento: " << lst4.back() << endl;

    if (lst4.empty()) {
        cout << "Lista vazia" << endl;
    }
    else {
        cout << "Lista nao esta vazia" << endl;
    }

    return 0;
}