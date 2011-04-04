#include <iostream>
#include <string>
using namespace std;

int main (void) {
	unsigned int bottles[9];
	
	while (cin >> bottles[0]) {
		for (int i = 1; i < 9; i++) cin >> bottles[i];
		
		unsigned int min = 1 << 31;
		string minimum = "BGC";
		
		// B G C B G C B G C
		// 0 1 2 3 4 5 6 7 8
		
		// BCG
		if (bottles[3] + bottles[6] + bottles[2] + bottles[8] + bottles[1] + bottles[4] < min){
			minimum = "BCG";
			min = bottles[3] + bottles[6] + bottles[2] + bottles[8] + bottles[1] + bottles[4];
		}
		// BGC
		if (bottles[3] + bottles[6] + bottles[1] + bottles[7] + bottles[2] + bottles[5] < min){
			minimum = "BGC";
			min = bottles[3] + bottles[6] + bottles[1] + bottles[7] + bottles[2] + bottles[5];
		}
		// CBG
		if (bottles[5] + bottles[8] + bottles[0] + bottles[6] + bottles[1] + bottles[4] < min){
			minimum = "CBG";
			min = bottles[5] + bottles[8] + bottles[0] + bottles[6] + bottles[1] + bottles[4];
		}
		// CGB
		if (bottles[5] + bottles[8] + bottles[1] + bottles[7] + bottles[0] + bottles[3] < min){
			minimum = "CGB";
			min = bottles[5] + bottles[8] + bottles[1] + bottles[7] + bottles[0] + bottles[3];
		}
		// GBC
		if (bottles[4] + bottles[7] + bottles[0] + bottles[6] + bottles[2] + bottles[5] < min){
			minimum = "GBC";
			min = bottles[4] + bottles[7] + bottles[0] + bottles[6] + bottles[2] + bottles[5];
		}
		// GCB
		if (bottles[4] + bottles[7] + bottles[2] + bottles[8] + bottles[0] + bottles[3] < min){
			minimum = "GCB";
			min = bottles[4] + bottles[7] + bottles[2] + bottles[8] + bottles[0] + bottles[3];
		}
		
		cout << minimum << " " << min << endl;
	}
	
	return 0;
}