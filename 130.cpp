#include <iostream>
using namespace std;

int main (void) {
	int n, k;
	int res;
	
	while (cin >> n >> k) {
		if (k == 0 && n == 0) break;
		
		int circle[n+1];		
		int pos;
		bool found = false;
		
		for (int j = 1; j <= n; j++) {
			pos = j;
			
			for (int i = 0; i <= n; i++)
				circle[i] = i;
			
			int counter = 0;
			int last[2];
			bool kill = true;
			
			int temp = 0;
			
			while (counter < n) {
				if (circle[pos] > 0) temp++;
				
				if (temp == k && circle[pos] > 0) {
					if (kill) {
						last[0] = pos;
						last[1] = circle[pos];
						circle[pos] = -1;
						kill = false;
						counter++;
					} else {
						circle[last[0]] = circle[pos];
						last[1] = circle[pos];
						circle[pos] = -1;
						pos = last[0];
						kill = true;
					}
					
					temp = 0;
				}
				
				pos++;
				if (pos > n) pos = 1;
			}
			
			if (last[1] == 1) {
				res = j;
				break;
			}
		}
		
		cout << res << endl;
	}
	
	return 0;
}