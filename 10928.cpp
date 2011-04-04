#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, p;
	int best;
	vector<int> results;
	string input;

	cin >> n;

	while (n--) {
		cin >> p;

		results.clear();

		getline(cin, input); // \n

		best = 100000;

		for (int i = 0; i < p; i++) {
			getline(cin, input);
			stringstream ss;

			ss << input;

			int tmp;

			int counter = 0;

			while (ss >> tmp)
				counter++;

			if (counter < best) {
				best = counter;
				results.clear();
				results.push_back(i+1);
			} else if (counter == best) {
				results.push_back(i+1);
			}
		}

		sort(results.begin(), results.end());

		for (int i = 0, sz = results.size(); i < sz; i++) {
			if (i > 0) cout << " ";
			cout << results[i];
		}
		cout << endl;
	}

	return 0;
}
