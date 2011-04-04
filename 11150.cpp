#include <iostream>
#include <cmath>
using namespace std;

int simulate(int n, int extra) {
	int result;
	int all = n + extra;

	result = n;

	while (all >= 3) {
		result += all / 3;
		all = all / 3 + all % 3;
	}

	if (all < extra)
		return 0;

	return result;
}

int main(void) {
	int n;

	while (cin >> n) {
		cout << max(simulate(n,0), max(simulate(n,1), simulate(n,2))) << endl;
	}

	return 0;
}
