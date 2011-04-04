#include <iostream>
#include <math.h>
using namespace std;

int main (void) {
	long long n;
	
	while (cin >> n) {
		if (n < 0) break;
		cout << n * (n + 1) / 2 + 1 << endl;
	}
	
	return 0;
}