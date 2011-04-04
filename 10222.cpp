#include <iostream>
#include <string>
using namespace std;

int main (void) {
	string keys = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	char c;
	
	while (cin.get(c)) {
		if (c == '\n' || c == '\t' || c == ' ') cout << c;
		else {
			size_t found = keys.find(tolower(c));
			cout << keys[found-2];
		}
	}
	
	return 0;
}