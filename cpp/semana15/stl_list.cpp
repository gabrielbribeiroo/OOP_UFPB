#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

int main() {
	list<int> numbers = {1, 2, 3, 4, 5};

	numbers.push_back(6);
	numbers.push_back(7);

	numbers.pop_back();

	for (int n : numbers) {
		cout << n << " ";
	}

	cout << endl;

    /*
        for (int i = 0; i < numbers.size(); i++) {
            numbers[i] *= 10;
            cout << numbers[i] << " ";
        }

        cout << endl;
    */

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		*it *= 10;
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}