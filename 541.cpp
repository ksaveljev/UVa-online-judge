#include <iostream>
using namespace std;

int main (void) {
	int n;
	int col, row;
	int count;
	bool corrupt;
	
	while (cin >> n) {
		if (n == 0) break;
		
		int matrix[n][n];
		col = row = -1;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		
		corrupt = false;
		for (int i = 0; i < n; i++) {
			count = 0;
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1) ++count;
			}
			if (count % 2 > 0) {
				if (row > -1) { corrupt = true; break; }
				else row = i;
			}
		}
		
		if (corrupt) { cout << "Corrupt" << endl; continue; }
		
		
		corrupt = false;
		for (int i = 0; i < n; i++) {
			count = 0;
			for (int j = 0; j < n; j++) {
				if (matrix[j][i] == 1) ++count;
			}
			if (count % 2 > 0) {
				if (col > -1) { corrupt = true; break; }
				else col = i;
			}
		}
		
		if (corrupt) { cout << "Corrupt" << endl; continue; }
		
		
		if (col > -1 && row > -1) {
			cout << "Change bit (" << row+1 << "," << col+1 << ")" << endl;
		} else if (col == -1 && row == -1) {
			cout << "OK" << endl;
		} else {
			cout << "Corrupt" << endl;
		}
	}
	
	return 0;
}