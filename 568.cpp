#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main(void) {
	map<int,int> m;
	int n;

	m[0] = 1;
	unsigned long long result = 1;
	for (int i = 1; i <= 10000; i++) {
		result *= i;
		while (result % 10 == 0)
			result /= 10;
		result %= 1000000;
		m[i] = result % 10;
	}

	while (cin >> n) {
		printf("%5d -> %d\n", n, m[n]);
	}
	
	return 0;
}
