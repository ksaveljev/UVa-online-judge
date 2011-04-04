#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned long long f[20];

int main(void) {
	int cases;
	unsigned long long n;
	string input;
	unsigned long long tmp = 1;

	f[0] = 1;
	for (int i = 1; i < 20; i++) {
		tmp *= i;
		f[i] = tmp;
	}
	
	cin >> cases;

	while (cases--) {
		cin >> input >> n;
		n++;

		sort(input.begin(), input.end());

		for (int i = 0, sz = input.size(); i < sz; i++) {
			int next = 0;
			while (f[input.size() - 1] < n) {
				n -= f[input.size() - 1];
				next++;
			}
			cout << input[next];
			input.erase(input.begin() + next);
		}

		cout << endl;
	}

	return 0;
}
