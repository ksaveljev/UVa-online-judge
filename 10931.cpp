#include <iostream>
#include <limits>
using namespace std;

void int2bin(int n) {
	for (int i = numeric_limits<int>::digits - 1; i >= 0; i--) {
		if (1 << i > n)
			continue;
		if (n & (1 << i))
			cout << 1;
		else
			cout << 0;
	}
}

int main(void) {
	int I;
	while (cin >> I) {
		if (I == 0)
			break;
		cout << "The parity of ";
		int2bin(I);
		cout << " is " << __builtin_popcount(I) << " (mod 2)." << endl;
	}

	return 0;
}
