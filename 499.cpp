#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool theTruthIsOutThere(char a, char b) {
	if (a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z')
		return true;
	else if (a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z')
		return false;
	else
		return a < b;
}

int main (void) {
	vector<char> result;
	map<char,int> occurance;
	string input;
	
	while (getline(cin, input)) {
		result.clear();
		occurance.clear();
		
		for (int i = 0; i < input.size(); i++) {
			if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') {
				if (occurance.find(input[i]) == occurance.end()) {
					occurance[input[i]] = 1;
				} else {
					occurance.find(input[i])->second += 1;
				}
			}
		}
		
		int max = 0;
		for (map<char,int>::iterator it = occurance.begin(); it != occurance.end(); it++) {
			if (it->second > max) max = it->second;
		}
		
		for (map<char,int>::iterator it = occurance.begin(); it != occurance.end(); it++) {
			if (it->second == max) result.push_back(it->first);
		}
		
		sort (result.begin(), result.end(), theTruthIsOutThere);
		
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
		cout << " " << occurance[result[0]] << endl;
	}
	
	return 0;
}