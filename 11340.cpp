#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cstdio>
using namespace std;

int main(void) {
	int cases;
	char c;
	int p;
	int k;
	string input;
	map<char,int> m;

	cin >> cases;

	while (cases--) {
		m.clear();

		cin >> k;

		getline(cin, input); // \n

		while (k--) {
			stringstream ss;
			getline(cin, input);
			ss << input;
			c = ss.get();
			ss >> p;
			m[c] = p;
		}

		cin >> k;
		
		int result = 0;

		getline(cin, input); // \n
		while (k--) {
			getline(cin, input);
			for (int i = 0, sz = input.size(); i < sz; i++) {
				if (m.find(input[i]) != m.end()) {
					result += m[input[i]];
				}
			}
		}

		printf("%.2f$\n", result/100.0);
	}

	return 0;
}
