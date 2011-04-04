#include <iostream>
#include <string>
using namespace std;

int main (void) {
	string input;
	
	while (cin >> input) {
		int prev = 0;
		for (int i = 0; i < input.size(); i++) {
			int n = 0;
			
			if (input[i] == 'B' || input[i] == 'F' || input[i] == 'P' || input[i] == 'V') {
				if (prev != 1) cout << "1";
				prev = 1;
			} else if (input[i] == 'C' || input[i] == 'G' || input[i] == 'J' || input[i] == 'K' || input[i] == 'Q' || input[i] == 'S' || input[i] == 'X' || input[i] == 'Z') {
				if (prev != 2) cout << "2";
				prev = 2;
			} else if (input[i] == 'D' || input[i] == 'T') {
				if (prev != 3) cout << "3";
				prev = 3;
			} else if (input[i] == 'L') {
				if (prev != 4) cout << "4";
				prev = 4;
			} else if (input[i] == 'M' || input[i] == 'N') {
				if (prev != 5) cout << "5";
				prev = 5;
			} else if (input[i] == 'R') {
				if (prev != 6) cout << "6";
				prev = 6;
			} else {
				prev = 0;
			}
		}
		cout << endl;
	}
	
	
	return 0;
}