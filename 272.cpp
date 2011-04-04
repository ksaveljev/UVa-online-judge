#include <iostream>
using namespace std;

int main (void) {
	char c;
	bool first = true;
	
	while (cin.get(c)) {
		if (c == '"') {
			if (first) { first = false; c = '`'; }
			else { first = true; c = '\''; }
			
			cout << c << c;
		} else {
			cout << c;
		}
	}
	
	return 0;
}