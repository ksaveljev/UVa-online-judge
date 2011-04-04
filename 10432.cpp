#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main (void) {
	double r, n;
	
	while (cin >> r >> n) {
		double res = 0.5 * n * r * r * sin((2*acos(0)/180) * (360.0/n));
		cout << fixed << setprecision(3) << res << endl;
	}
}