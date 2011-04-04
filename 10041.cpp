#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long ulong;

int main (void) {
	int n;
	int a,b;
	vector<int> streets;
	
	cin >> n;
	
	while (n--) {
		streets.clear();
		
		cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> b;
			streets.push_back (b);
		}
		
		ulong minimum = 5000*30000;
		for (int i = 0; i < a; i++) {
			ulong counter = 0;
			for (int j = 0; j < a; j++) {
				counter += abs (streets[i] - streets[j]);
			}
			if (counter < minimum) minimum = counter;
		}
		
		cout << minimum << endl;
	}
	
	return 0;
}