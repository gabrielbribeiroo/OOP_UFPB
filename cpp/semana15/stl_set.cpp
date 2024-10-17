#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

int main() {
	set<int> numbers = {4, 2, 6, 3, 1, 5};

	numbers.insert(0);
	numbers.insert(8);
	numbers.insert(7);

	for (int n : numbers) {
		cout << n << " ";
	}

	cout << endl;

	for (set<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}