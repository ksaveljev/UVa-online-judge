#include <iostream>
#include <string>
using namespace std;

int main (void) {
	string s1, s2;
	int pos = 0;
	
	while (cin >> s1 >> s2) {
		pos = 0;
		bool found = false;
		for (int i = 0; i < s1.size(); i++) {
			found = false;
			for (int y = pos; y < s2.size(); y++) {
				if (s1[i] == s2[y]) {
					pos = y + 1;
					found = true;
					break;
				}
			}
			if (!found) break;
		}
		
		if (found) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}