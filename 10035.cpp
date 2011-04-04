#include <iostream>
#include <string>
using namespace std;


int main (void) {
	string a, b;
	int counter;
	int r;
	
	while (cin >> a >> b) {
		if (a == "0" && b == "0") break;
		
		reverse (a.begin(), a.end());
		reverse (b.begin(), b.end());
		
		if (a.size() < b.size()) swap (a, b);
		
		counter = 0; r = 0;
		for (int i = 0; i < b.size(); i++) {
			int temp = a[i] - 48 + b[i] - 48 + r;
			if (temp > 9) {
				r = 1;
				counter++;
			} else {
				r = 0;
			}
		}
		
		for (int i = b.size(); i < a.size(); i++) {
			int temp = a[i] - 48 + r;
			if (temp > 9) {
				r = 1;
				counter++;
			} else {
				r = 0;
			}
		}

		
		if (counter == 0) cout << "No carry operation." << endl;
		else if (counter == 1) cout << "1 carry operation." << endl;
		else cout << counter << " carry operations." << endl;
	}
	
	return 0;
}