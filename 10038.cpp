#include <iostream>
#include <vector>
using namespace std;

int main (void) {
	int n;
	int *num;
	vector<int> taken;
	
	num = new int[3000];
	
	while (cin >> n) {
		if (n == 0) {
			cout << "Not jolly" << endl;
			continue;
		}
		
		taken.clear();
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			if (i > 0) taken.push_back(abs(num[i] - num[i-1])); 
		}
		
		sort (taken.begin(), taken.end());
		
		bool good = true;
		for (int i = 0; i < taken.size(); i++) {
			if (taken[i] != i+1) {
				good = false;
				break;
			}
		}
		
		if (good) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	
	delete num;
	
	return 0;
}