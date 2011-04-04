#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef unsigned long u_long;

int main (void) {
	vector<u_long> left;
	vector<u_long> right;
	u_long prev1 = 1, prev2 = 0;
	
	
	left.push_back(6);
	left.push_back(35);
	for (int i = 2; i < 10; i++)
		left.push_back (6 * left[i-1] - left[i-2]);
	
	right.push_back(8);
	right.push_back(49);
	for (int i = 2; i < 10; i++)
		right.push_back (6 * right[i-1] - right[i-2] + 2);
	
	for (int i = 0; i < 10 ; i++)
		cout << setw(10) << left[i] << setw(10) << right[i] << endl;
	
	return 0;
}