#include <iostream>
#include <map>
using namespace std;

typedef pair<int,int> p;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	
	return a;
}

int main(void) {
	int n;
	int tmp;
	int result;
	map<p,int> m;

	while (cin >> n) {
		if (n == 0)
			break;

		result = 0;

		for (int i = 1; i < n; i++) {
			for (int y = i + 1; y <= n; y++) {
				if (m.find(make_pair(i, y)) == m.end()) {
					tmp = gcd(i, y);
					m[make_pair(i, y)] = tmp;
					result += tmp;
				} else {
					result += m[make_pair(i, y)];
				}
			}
		}

		cout << result << endl;
	}

	return 0;
}
