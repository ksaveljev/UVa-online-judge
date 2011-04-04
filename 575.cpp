#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main (void) {
	string input;
	
	while (cin >> input) {
		if (input == "0") break;
		
		int n = input.size();
		int res = 0;
		
		for (int i = 0; i < n; i++) {
			res += ((int)input[i] - 48) * (pow(2, n - i) - 1);
		}
		
		cout << res << endl;
	}
	
	return 0;
}