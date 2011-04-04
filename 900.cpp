#include <iostream>
using namespace std;

int main (void) {
	unsigned long long fib[51];
	fib[0] = fib[1] = 1;
	
	for (int i = 2; i < 51; i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	int n;
	
	while (cin >> n) {
		if (n == 0) break;
		cout << fib[n] << endl;
	}
	
	return 0;
}