#include <iostream>
using namespace std;

int main (void) {
	int n;
	int counter = 0;
	
	while (cin >> n) {
		if (n == 0) break;
		
		++counter;
		int heights[n];
		int sum = 0;
		
		for (int i = 0; i < n; i++) {
			cin >> heights[i];
			sum += heights[i];
		}
		
		int average = sum / n;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (heights[i] > average)
				res += heights[i] - average;
		}
		
		cout << "Set #" << counter  << endl;
		cout << "The minimum number of moves is " << res << "." << endl << endl;
	}
	
	return 0;
}