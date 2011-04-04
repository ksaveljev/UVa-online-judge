#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_prime(int n) {
	if (n == 1 || n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 3, sz = sqrt(n) + 1; i < sz; i++) {
		if (n % i == 0)
			return false;
	}
	
	return true;
}

int main(void) {
	string input;
	int tmp;

	while (cin >> input) {
		tmp = 0;
		for (int i = 0, sz = input.size(); i < sz; i++) {
			if (input[i] >= 'a' && input[i] <= 'z') {
				tmp += input[i] - 'a' + 1;
			} else if (input[i] >= 'A' && input[i] <= 'Z') {
				tmp += input[i] - 'A' + 27;
			}
		}
		if (is_prime(tmp)) {
			cout << "It is a prime word." << endl;
		} else {
			cout << "It is not a prime word." << endl;
		}
	}


	return 0;
}
