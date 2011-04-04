#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string,double> p;

bool theTruthIsOutThere(const p& a, const p& b) {
	return a.first < b.first;
}

int main(void) {
	int n;
	string input;
	map<string,int> m;
	vector<p> result;
	

	cin >> n;

	getline(cin, input); // \n
	getline(cin, input); // empty line

	while (n--) {
		m.clear();
		result.clear();

		int total = 0;

		while (getline(cin, input)) {
			if (input == "")
				break;

			total++;

			if (m.find(input) == m.end())
				m[input] = 1;
			else
				m[input] += 1;
		}

		for (map<string,int>::iterator it = m.begin(); it != m.end(); it++) {
			result.push_back(make_pair(it->first, it->second * 100.0 / total));
		}

		sort(result.begin(), result.end(), theTruthIsOutThere);

		for (int i = 0, sz = result.size(); i < sz; i++) {
			cout << result[i].first << " ";
			printf("%.4f\n", result[i].second);
		}

		if (n > 0)
			cout << endl;
	}

	return 0;
}
