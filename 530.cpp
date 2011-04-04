#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	unsigned int n, k;
	vector<unsigned int> top, bottom;

	while (cin >> n >> k) {
		if (n == 0 && k == 0)
			break;

		top.clear();
		bottom.clear();

		if (n - k > k)
			k = n - k;

		for (unsigned int i = k + 1; i <= n; i++)
			top.push_back(i);

		for (unsigned int i = 2; i <= n - k; i++)
			bottom.push_back(i);

		for (unsigned int i = 0, sz = top.size(); i < sz; i++) {
			for (unsigned int y = 0, sz2 = bottom.size(); y < sz2; y++) {
				if (bottom[y] > 1 && top[i] % bottom[y] == 0) {
					top[i] /= bottom[y];
					bottom[y] = 1;
				}
			}
		}

		unsigned long long t = 1;
		unsigned long long b = 1;

		for (int i = 0, sz = top.size(); i < sz; i++)
			t *= top[i];

		for (int i = 0, sz = bottom.size(); i < sz; i++)
			b *= bottom[i];

		cout << t / b << endl;
	}

	return 0;
}
