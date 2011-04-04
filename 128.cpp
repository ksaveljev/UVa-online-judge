#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

typedef long long llong;

int main (void) {
	string input;
	int g = 34943;
	
	while (getline(cin, input)) {
		if (input == "#") break;
		
		if (input.size() == 0) cout << "00 00" << endl;
		else {
			llong temp = input[0];
			for (int i = 1; i < input.size(); i++) {
				temp %= g;
				temp <<= 8;
				temp += input[i];
			}
			temp <<= 16;
			int result = g - (temp % g);
			
			char buf[5];
			sprintf(buf, "%04X", result);
			
			cout << buf[0] << buf[1] << " " << buf[2] << buf[3] << endl;
		}
	}
	
	return 0;
}