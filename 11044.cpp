#include <iostream>
using namespace std;

int main(void) {
	int t, n, m;

	cin >> t;

	while (t--) {
		cin >> n >> m;
		n -= 2;
		if (n % 3 == 0)
			n /= 3;
		else
			n = n / 3 + 1;

		m -= 2;
		if (m % 3 == 0)
			m /= 3;
		else
			m = m / 3 + 1;

		cout << n * m << endl;
	}

	return 0;
}
