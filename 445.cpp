#include <iostream>
using namespace std;

int main (void) {
	char c;
	int count = 0;
	int i;
	
	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			count += c - 48;
		} else if (c == 'b') {
			for (i = 0; i < count; i++)
				cout << ' ';
			count = 0;
		} else if (c == '!') {
			cout << endl;
		} else if (c == '\n') {
			cout << c;
		} else {
			for (i = 0; i < count ;i++)
				cout << c;
			count = 0;
		}
	}
	
	return 0;
}