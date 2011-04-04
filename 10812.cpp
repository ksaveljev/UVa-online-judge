#include <iostream>
using namespace std;

int main(void) {
	int n, s, d;

	cin >> n;

	while (n--) {
		cin >> s >> d;
		// x + y = s
		// |x - y| = d
		int tmp = (s + d) / 2;

		if ((tmp * 2 == s + d) && (s - tmp) >= 0) {
			cout << tmp << " " << s - tmp << endl;
		} else {
			cout << "impossible" << endl;
		}
	}

	return 0;
}
