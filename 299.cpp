#include <iostream>
using namespace std;

int main (void) {
	int n, num;
	
	cin >> n;
	
	while (n--) {
		cin >> num;
		int sw[num];
		
		for (int i = 0; i < num; i++)
			cin >> sw[i];
		
		int counter = 0;
		int temp;
		bool swapped = true;
		do {
			swapped = false;
			for (int i = 0; i < num - 1; i++) {
				if (sw[i] > sw[i+1]) {
					++counter;
					temp = sw[i];
					sw[i] = sw[i+1];
					sw[i+1] = temp;
					swapped = true;
				}
			}
		} while (swapped);
		
		cout << "Optimal train swapping takes " << counter << " swaps." << endl;
	}
	
	return 0;
}