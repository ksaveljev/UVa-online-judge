#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool theTruthIsOutThere(const pair<char,int> &a, const pair<char,int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second > b.second;
	}
}

int main(void) {
	int n;
	string input;
	map<char,int> m;
	vector< pair<char,int> > v;
	
	cin >> n;
	
	getline(cin, input); // fetching \n
	
	while (n--) {
		getline(cin, input);
		for (int i = 0, y = input.size(); i < y; i++) {
			if (toupper(input[i]) >= 'A' && toupper(input[i]) <= 'Z') {
				if (m.find(toupper(input[i])) != m.end()) {
					m[toupper(input[i])] += 1;
				} else {
					m[toupper(input[i])] = 1;
				}
			}
		}
	}
	
	for (map<char,int>::iterator it = m.begin(); it != m.end(); it++) {
		v.push_back(pair<char,int>(it->first, it->second));
	}
	
	sort (v.begin(), v.end(), theTruthIsOutThere);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	
	return 0;
}
