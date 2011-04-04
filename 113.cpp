#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main (void) {
	int n;
	double p;
	
	while (cin >> n >> p) {
		cout << setiosflags(ios::fixed) << setprecision(0) << pow(p, 1.0/n) << endl;
	}
	
	return 0;
}