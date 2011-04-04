#include <iostream>
#include <vector>
using namespace std;

int main (void) {
	vector<int> input;
	int n;
	
	while (cin >> n) {
		input.push_back(n);
		sort (input.begin(), input.end());
		
		if (input.size() % 2 == 0) {
			long med = (input[input.size()/2] + input[input.size()/2-1]) / 2;
			cout << med << endl;
		} else {
			cout << input[input.size()/2] << endl;
		}
	}
	
	return 0;
}