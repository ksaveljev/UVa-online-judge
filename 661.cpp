#include <iostream>
using namespace std;

int main(void) {
	unsigned long *device;
	bool *state;
	unsigned long n, m, c, d;
	unsigned long cases = 0;

	while (cin >> n >> m >> c) {
		if (n == 0 && m == 0 && c == 0)
			break;

		device = new unsigned long[n];
		state = new bool[n];

		for (unsigned long i = 0; i < n; i++)
			state[i] = false;

		for (unsigned long i = 0; i < n; i++) {
			cin >> device[i];
		}

		unsigned long max = 0;
		unsigned long cur = 0;
		while (m--) {
			cin >> d;
			d--;
			if (state[d]) {
				state[d] = false;
				cur -= device[d];
			} else {
				state[d] = true;
				cur += device[d];
				if (cur > max)
					max = cur;
			}
		}

		cases++;

		cout << "Sequence " << cases << endl;
		if (max > c) {
			cout << "Fuse was blown." << endl;
		} else {
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max << " amperes." << endl;
		}

		cout << endl;

		delete [] device;
		delete [] state;
	}

	return 0;
}
