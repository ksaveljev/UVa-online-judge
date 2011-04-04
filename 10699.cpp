#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int n) {
	for (int i = 3, sz = sqrt(n); i <= sz; i+=2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(void) {
	vector<int> primes;
	int n;

	primes.push_back(2);

	for(int i = 3; i < 1000000; i+=2) {
		if (is_prime(i))
			primes.push_back(i);
	}
	
	while (cin >> n) {
		if (n == 0)
			break;

		int num = n;
		int counter = 0;

		for (int i = 0, sz = primes.size(); i < sz; i++) {
			if (n % primes[i] == 0) {
				counter++;
				while (n % primes[i] == 0) {
					n /= primes[i];
				}
				if (n == 1)
					break;
			}
		}

		cout << num << " : " << counter << endl;
	}
	return 0;
}
