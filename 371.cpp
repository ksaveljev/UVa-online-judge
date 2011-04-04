#include <iostream>
#include <map>
using namespace std;

struct result {
	unsigned long n;
	unsigned long values;
};

int main(void) {
	unsigned long l, h, v;
	unsigned long tmp;
	map<unsigned long, unsigned long> m;

	while (cin >> l >> h) {
		if (l == 0 && h == 0)
			break;
		
		if (h < l) {
			tmp = l;
			l = h;
			h = tmp;
		}

		result r;
		r.n = 0;
		r.values = 0;

		for (int i = l; i <= h; i++) {
			tmp = i;
			unsigned long seq = 0;
			while (true) {
				if (m.find(tmp) == m.end()) {
					seq++;
					if (tmp % 2 == 0) {
						tmp /= 2;
					} else {
						tmp = 3 * tmp + 1;
					}

					if (tmp == 1)
						break;
				} else {
					seq += m[tmp];
					break;
				}
			}
			m[i] = seq;
			if (seq > r.values) {
				r.n = i;
				r.values = seq;
			}
		}

		cout << "Between " << l << " and " << h << ", " << r.n << " generates the longest sequence of " << r.values << " values." << endl;
	}


	return 0;
}
