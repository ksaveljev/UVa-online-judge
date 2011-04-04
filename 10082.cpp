#include <iostream>
#include <string>
using namespace std;

int main (void) {
	string keys = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	
	while (cin.get(c)) {
		if (c == '\n' || c == ' ') cout << c;
		else {
			size_t found = keys.find(c);
			cout << keys[found-1];
		}
	}
	
	return 0;
}