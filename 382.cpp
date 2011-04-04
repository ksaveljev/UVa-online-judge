#include <iostream>
#include <iomanip>
using namespace std;

int main (void) {
	int n;
	
	cout << "PERFECTION OUTPUT" << endl;
	
	while (cin >> n) {
		if (n == 0) break;
		
		int sum = 0;
		for (int i = 1; i <= n/2; i++) {
			if (n % i == 0) sum += i;
		}
		
		cout << setw(5) << n << "  ";
		if (sum == n)
			cout << "PERFECT";
		else if (sum < n)
			cout << "DEFICIENT";
		else
			cout << "ABUNDANT";
		
		cout << endl;
	}
	
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}