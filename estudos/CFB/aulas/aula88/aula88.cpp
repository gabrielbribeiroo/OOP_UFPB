#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vct = {9, 2, 7, 4, 5, 6, 3, 8, 0, 1};
    vector<int>::iterator it;
    // vector<int> vct2;

    it = vct.end()-1;
    vct.erase(it); // Remove o elemento

    /*
    it = vct.begin();
    vct.insert(it, 5);

    for (auto x:vct) {
        cout << x << endl;
    }
    */

    /*
    vct1.push_back(0); // Adiciona um elemento ao final do vetor
    vct1.pop_back(); // Remove o último elemento do final do vetor
    */

    /*
    vct2.assign(10, 0); // Inicializa as 10 posições com 0
    vct2.assign(vct1.begin(), vct1.end()); // Copia os elementos do vetor

    for (auto x:vct2) {
        cout << x << endl;
    }
    */

    /*
    cout << vct[3] << endl;
    cout << vct.at(3) << endl;
    cout << vct.front() << endl;
    cout << vct.back() << endl;
    */

    /*
    if (vct.empty()) {
        cout << "Vetor vazio" << endl;
    }
    else {
        cout << "Array NAO esta vazio" << endl;
    }
    */

    /*
    for (auto it = vct.begin(); it!= vct.end(); it++) {
        cout << *it;
    }
    */

    /*
    cout << vct.size() << endl;
    cout << vct.max_size() << endl;

    vct.resize(5);
    cout << vct.size() << endl;

    for (auto x:vct) {
        cout << x << endl;
    }

    cout << endl;

    vct.shrink_to_fit();

    cout << vct.capacity() << endl;
    */

    return 0;
}