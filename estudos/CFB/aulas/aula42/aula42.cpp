#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> num1;
    vector<int> num2;
    int tam1, tam2, i;

    // Inserção de elementos no vetor
    num1.push_back(1);
    num1.push_back(2);
    num1.push_back(3);
    num1.push_back(4);
    num1.push_back(5);
    num1.insert(num1.end()-1, 888); // Adiciona um elemento em determinada posição
    num1.erase(num1.end()-2); // Exclui um elemento em determinada posição

    num2.push_back(6);
    num2.push_back(7);
    num2.push_back(8);
    num2.push_back(9);
    num2.push_back(10);

    // num1.swap(num2); // Troca os elementos entre os vetores

    tam1 = num1.size(); // Tamanho do vetor
    cout << endl << "Tamanho do vetor 1: " << tam1 << endl;
    cout << "Primeiro valor de num1: " << num1.front() << endl;
    cout << "Ultimo valor de num1: " << num1.back() << endl;
    cout << "Valor do meio de num1: " << num1.at(tam1/2) << endl;    
    cout << "Elementos do vetor 1: ";
    for (i=0; i<tam1; i++) {
        cout << num1[i] << " ";
    }
    cout << endl;
    while(!num1.empty()) {
        num1.pop_back(); // Retira o último elemento, enquanto não estiver vazio
    }
    cout << "Novo tamanho de num1: " << num1.size() << endl;
    cout << endl;

    tam2 = num2.size(); // Tamanho do vetor
    cout << "Tamanho do vetor 2: " << tam2 << endl;
    cout << "Primeiro valor de num2: " << num2.front() << endl;
    cout << "Ultimo valor de num2: " << num2.back() << endl;
    cout << "Valor do meio de num2: " << num2.at(tam2/2) << endl; 
    cout << "Elementos do vetor 2: ";
    for (i=0; i<tam2; i++) {
        cout << num2[i] << " ";
    }
    num2.clear(); // Limpeza dos elementos do vetor
    cout << endl << endl;

    return 0;
}
