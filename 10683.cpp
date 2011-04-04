#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void) {
	int h, m, s, c;
	string input;

	while (cin >> input) {
		h = (input[0]-'0') * 10 + (input[1]-'0');
		m = (input[2]-'0') * 10 + (input[3]-'0');
		s = (input[4]-'0') * 10 + (input[5]-'0');
		c = (input[6]-'0') * 10 + (input[7]-'0');

		int result = ((h * 60 + m) * 60 + s) * 100 + c;
		printf("%07ld\n", result * 125 / 108);
	}

	return 0;
}
