#include <iostream>
using namespace std;

int main (void) {
	int n;
	
	cin >> n;
	
	while (n--) {
		int a;
		cin >> a;
		int nums[a];
		
		int sum = 0;
		for (int i = 0; i < a; i++) { cin >> nums[i]; sum += nums[i]; }
		
		double medium = sum / a;
		int good = 0;
		for (int i = 0; i < a; i++) { if (nums[i] > medium) good++; }
		
		printf ("%.3f%%\n", (1.0 * good / a) * 100);
	}
	
	return 0;
}