#include <iostream>
#include <cmath>
using namespace std;

int mypower(int a, int b) {
	int result = 1;

	for (int i = 0; i < b; i++) {
		result *= a;
	}

	return result;
}

int hex_to_int(int n) {
	int result = 0;
	int counter = 0;
	int tmp;

	while (n > 0) {
		tmp = n % 10;
		n /= 10;
		result += tmp * mypower(16, counter);
		counter++;
	}

	return result;
}

int main(void) {
	int n, num;

	cin >> n;

	while (n--) {
		cin >> num;
		cout << __builtin_popcount(num) << " " << __builtin_popcount(hex_to_int(num)) << endl;
	}

	return 0;
}
