#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

bool isPrime (int n) {
	int temp = sqrt (double(n));
	for (int i = 3; i < temp + 1; i+=2)
		if (n % i == 0) return false;
	return true;
}

int main (void) {
	vector<int> primesv;
	map<int,bool> primes;
	
	primesv.push_back(2);
	
	for (int i = 3; i < 1000000; i+=2) {
		if (isPrime(i)) {
			primesv.push_back(i);
			primes.insert(pair<int,bool>(i,true));
		}
	}
	
	int n;
	while (cin >> n) {
		if (n == 0) break;
		
		for (int i = 0; i < primesv.size(); i++) {
			if (primes[n - primesv[i]] == true) {
				cout << n << " = " << primesv[i] << " + " << n - primesv[i] << endl;
				break;
			}
		}
	}

	return 0;
}