#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define LIMIT 2147483647

bool is_prime(int n) {
	for (int i = 3, sz = sqrt(n); i <= sz; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	int n;
	bool first;
	vector<int> primes;

	primes.push_back(2);

	for (int i = 3, sz = sqrt(LIMIT); i <= sz; i += 2) {
		if (is_prime(i))
			primes.push_back(i);
	}
	
	while (cin >> n) {
		if (n == 0)
			break;

		cout << n << " = ";

		first = true;

		if (n < 0) {
			cout << "-1 x ";
			n = -n;
		}

		for (int i = 0, sz = primes.size(); i < sz; i++) {
			if (n % primes[i] == 0) {
				while (n % primes[i] == 0) {
					if (!first)
						cout << " x ";

					first = false;
					cout << primes[i];

					n /= primes[i];
				}
			}
		}

		if (n > 1) {
			if (!first)
				cout << " x ";
			cout << n;
		}

		cout << endl;
	}

	return 0;
}
