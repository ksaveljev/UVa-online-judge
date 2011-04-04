#include <iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

int main (void) {
	int nregions = 0, nicons = 0;
	int regions[25][4];
	int icons[50][3];
	string command;
	int x, y;
	priority_queue< int, vector<int>, greater<int> > clicked;
	bool checked = false;
	
	while (cin >> command) {
		if (command == "#")
			break;
		else if (command == "I") {
			cin >> icons[nicons][0] >> icons[nicons][1];
			icons[nicons][2] = 1;
			nicons++;
		} else if (command == "R") {
			cin >> regions[nregions][0] >> regions[nregions][1] >> regions[nregions][2] >> regions[nregions][3];
			nregions++;
		} else if (command == "M") {
			cin >> x >> y;
			
			// checking all icons for their visibility
			if (!checked) {
				for (int i = 0; i < nicons; i++) {
					for (int j = 0; j < nregions; j++) {
						if (icons[i][0] >= regions[j][0] && icons[i][1] >= regions[j][1] && icons[i][0] <= regions[j][2] && icons[i][1] <= regions[j][3]) {
							icons[i][2] = 0; // icon is invisible
							break;
						}
					}
				}
				
				checked = true;
			}
			
			bool selected = false;
			for (int i = nregions - 1; i >= 0; i--) {
				if (x >= regions[i][0] && y >= regions[i][1] && x <= regions[i][2] && y <= regions[i][3]) {
					selected = true;
					cout << char(65 + i) << endl;
					break;
				}
			}
			
			if (selected) continue;
			
			while (!clicked.empty())
				clicked.pop();
			double min = 10000000.0;
			for (int i = 0; i < nicons; i++) {
				if (icons[i][2] == 1) {
					double temp = pow(x - icons[i][0], 2) + pow(y - icons[i][1], 2);
					if (temp == min) clicked.push(i);
					else if (temp < min) {
						while (!clicked.empty()) clicked.pop();
						clicked.push(i);
						min = temp;
					}
				}
			}
			
			while (!clicked.empty()){
				printf("%3.d", clicked.top() + 1);
				clicked.pop();
			}
			cout << endl;
		}
	}
	
	
	return 0;
}