#include <iostream>
using namespace std;

int f91(int n) {
	return n <= 100 ? f91(f91(n+11)) : n - 10;
}

int main(void) {
	int n;

	while (cin >> n) {
		if (n == 0)
			break;

		cout << "f91(" << n << ") = " << f91(n) << endl;
	}

	return 0;
}
