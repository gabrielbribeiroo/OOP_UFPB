#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::deque;

int main() {
	deque<int> numbers = {1, 2, 3, 4, 5};

	for (int i = 0; i < numbers.size(); i++) {
		cout << "[" << i << "] " << numbers[i] << endl;
	}

	cout << endl;

	numbers.push_front(0);
	numbers.push_front(-1);

	numbers.pop_front();

	numbers.push_back(6);
	numbers.push_back(7);

	numbers.pop_back();

	for (int n : numbers) {
		cout << n << " ";
	}

	cout << endl;

	for (int i = 0; i < numbers.size(); i++) {
		numbers[i] *= 10;
		cout << "[" << i << "] = " << numbers[i] << endl;
	}

	cout << endl;

	for (deque<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		*it *= 10;
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}