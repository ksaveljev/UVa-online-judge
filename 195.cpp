#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool theTruthIsOutThere (const char a, const char b) {
	if (tolower(a) < tolower(b)) return true;
	else if (tolower(a) == tolower(b)) return a < b;
	else return false;
}

int main (void) {
	string input;
	vector<char> chars;
	int n;
	
	cin >> n;
	
	while (n--) {
		cin >> input;
		chars.clear();
		
		for (int i = 0; i < input.size(); i++)
			chars.push_back (input[i]);
			
		sort (chars.begin(), chars.end(), theTruthIsOutThere);
		
		do {
			for (int i = 0; i < chars.size(); i++)
				cout << chars[i];
			cout << endl;
		} while (next_permutation (chars.begin(), chars.end(), theTruthIsOutThere));
	}
	
	return 0;
}