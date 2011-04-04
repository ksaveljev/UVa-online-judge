#include <iostream>
#include <iomanip>
using namespace std;

int main (void) {
	bool trainees[20];
	int n, k, m;
	
	while (cin >> n >> k >> m) {
		if (n == 0 && k == 0 && m == 0) break;
		
		for (int i = 0; i < 20; i++) trainees[i] = false;
		for (int i = 0; i < n; i++) trainees[i] = true;
		
		int left = n-1, right = 0;
		int counter = 0;
		int j;
		int sentoff = 0;
		
		while (sentoff < n) {
			j = right;
			counter = 0;
			while (counter < m) {
				if (j == 0) j = n - 1; else --j;
				if (trainees[j] == true)
					counter++;
			}
			
			right = j;
			
			j = left;
			counter = 0;
			while (counter < k) {
				if (j == n-1) j = 0; else ++j;
				if (trainees[j] == true)
					counter++;
			}
			
			left = j;
			
			if (sentoff > 0) cout << ",";
			if (left == right) {
				cout << setw(3) << left + 1;
				sentoff += 1;
			} else {
				cout << setw(3) << left + 1 << setw(3) << right + 1;
				sentoff += 2;
			}
			
			
			trainees[left] = false;
			trainees[right] = false;
		}
		cout << endl;
	}
	
	
	return 0;
}