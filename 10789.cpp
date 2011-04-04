#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
	if (n < 2)
		return false;

	if (n == 2)
		return true;
	
	if (n % 2 == 0)
		return false;
	
	for (int i = 3, sz = sqrt(n); i <= sz; i += 2) {
		if (n % i == 0)
			return false;
	}
	
	return true;
}

int main(void) {
	int t;
	string input;
	map<char,int> m;
	vector<char> results;

	cin >> t;

	for (int cases = 0; cases < t; cases++) {
		cout << "Case " << cases+1 << ": ";

		cin >> input;
		m.clear();
		results.clear();

		for (int i = 0, sz = input.size(); i < sz; i++) {
			if (m.find(input[i]) == m.end()) {
				m[input[i]] = 1;
			} else {
				m[input[i]] += 1;
			}
		}

		for (map<char,int>::iterator it = m.begin(); it != m.end(); it++) {
			if (is_prime((*it).second)) {
				results.push_back((*it).first);
			}
		}

		sort(results.begin(), results.end());

		for (int i = 0, sz = results.size(); i < sz; i++) {
			cout << results[i];
		}

		if (results.size() == 0)
			cout << "empty";

		cout << endl;
	}

	return 0;
}
