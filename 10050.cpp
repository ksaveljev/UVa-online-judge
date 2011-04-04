#include <iostream>
using namespace std;

int main(void) {
	int t, n, p, h;

	cin >> t;

	while (t--) {
		cin >> n;

		char days[n+1];
		for (int i = 1; i <= n; i++) {
			days[i] = '0';
		}
		
		cin >> p;

		while (p--) {
			cin >> h;
			// do stuff
			int i = 1;
			while (true) {
				if (i * h > n)
					break;
				days[i*h] = '1';
				i++;
			}
		}

		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (days[i] == '1' && ((i-1)%7!=5) && ((i-1)%7!=6)) {
				result++;
			}
		}

		cout << result << endl;
	}

	return 0;
}
