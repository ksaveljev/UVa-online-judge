#include <iostream>
using namespace std;

int main (void) {
	int n[9];
	
	while (cin >> n[8]) {
		for (int i = 7; i >= 0; i--) cin >> n[i];
		
		bool first = true;
		
		for (int i = 8; i >= 0; i--) {
			if (n[i] != 0) {
				if (first) {
					if (n[i] < 0) { cout << "-"; n[i] = -n[i]; }
					if (i == 0 || n[i] != 1)
						cout << n[i];
					if (i > 1)
						cout << "x^" << i;
					else if (i == 1)
						cout << "x";
					first = false;
				} else {
					if (n[i] < 0) { cout << " - "; n[i] = -n[i]; }
					else cout << " + ";
					if (i == 0 || n[i] != 1)
						cout << n[i];
					if (i > 1)
						cout << "x^" << i;
					else if (i == 1)
						cout << "x";
				}
			}
		}
		
		if (first) cout << "0";
		
		cout << endl;
	}
	
	
	return 0;
}