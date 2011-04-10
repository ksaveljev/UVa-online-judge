#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

queue<string> result;

void generate (char c) {
	string s = result.front();
	result.pop();
	
	for (int i = 0; i <= s.size(); i++) {
		string temp(s);
		temp.insert(temp.begin() + i, c);
		result.push(temp);
	}
}

void knuth (char c) {
	if (result.empty()) {
		string s = "";
		s.insert(s.begin(), c);
		result.push(s);
	} else {
		for (int i = 0, y = result.size(); i < y; i++) {
			generate(c);
		}
	}
}

int main (void) {
	string input;
	int counter = 0;
	
	while (cin >> input) {
		if (counter) cout << endl;
		else counter++;
		
		for (int i = 0; i < input.size(); i++) {
			knuth(input[i]);
		}
		
		while (!result.empty()) {
			cout << result.front() << endl;
			result.pop();
		}
	}

	return 0;
}
