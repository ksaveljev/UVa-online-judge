#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
using namespace std;

bool isPrime(int n) {
	for (int i = 3; i <= sqrt((double)n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main (void) {
	vector<int> primes;
	int n, c;
	
	primes.push_back(1);
	primes.push_back(2);
	
	for (int i = 3; i < 1000; i += 2) {
		if (isPrime(i)) primes.push_back(i);
	}
	
	while (cin >> n >> c) {
		deque<int> p;
		
		for (int i = 0; i < primes.size(); i++) {
			if (primes[i] > n) {
				break;
			} else {
				p.push_back(primes[i]);
			}
		}
		
		if (p.size() % 2 == 0) {
			while (p.size() > c*2) {
				p.pop_front();
				p.pop_back();
			}
		} else {
			while (p.size() > (c*2 - 1)) {
				p.pop_front();
				p.pop_back();
			}
		}

		cout << n << " " << c << ":";
		while (!p.empty()) {
			cout << " " << p.front();
			p.pop_front();
		}
		cout << endl << endl;
	}
	
	return 0;
}