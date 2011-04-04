#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime (int n) {
	int temp = sqrt (double(n));
	for (int i = 3; i < temp + 1; i+=2) {
		if (n % i == 0) return false;
	}
	
	return true;
}

int main (void) {
	vector<int> primes;
	vector<int>::iterator it;
	int n;
	
	primes.push_back (2);
	for (int i = 3; i < 1<<15; i+=2) {
		if (isPrime (i))
			primes.push_back(i);
	}
	
	while (cin >> n) {
		if (n == 0) break;
		
		int pos = 0;
		int counter = 0;
		while (primes[pos] <= n/2) {
			it = find (primes.begin(), primes.end(), n - primes[pos]);
			if (it != primes.end()) counter++;
			++pos;
		}
		
		cout << counter << endl;
	}
	
	return 0;
}