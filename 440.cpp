#include <iostream>
#include <deque>
using namespace std;

int main (void) {
	int n, current;
	deque<int> regions;
	
	while (cin >> n) {
		if (n == 0) break;
		
		int m = 0;
		while (++m) {
			regions.clear();
			for (int i = 1; i <= n; i++) regions.push_back(i);
			
			regions.pop_front();
			regions.push_back(0);
			
			int count = 1;
			int taken = 0;
			int c = 0;
			while (count < n) {
				if (regions.front() > 0) {
					c++;
					taken = regions.front();
					regions.pop_front();
					if (c == m) {
						c = 0;
						count++;
						if (count < n && taken == 2) {
							taken = 0;
							break;
						}
						regions.push_back(0);
					} else {
						regions.push_back(taken);
					}
				} else {
					regions.pop_front();
					regions.push_back(0);
				}
			}
			
			if (taken == 2) break;
		}
		
		cout << m << endl;
	}
	
	return 0;
}