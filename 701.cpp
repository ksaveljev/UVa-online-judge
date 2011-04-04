#include <iostream>
#include <math.h>
using namespace std;

int num_length (unsigned int n) {
	return log10(n) + 1;
}

int main (void) {
	unsigned int n;
	double a, b;
	unsigned int temp1, temp2;
	
	while (cin >> n) {
		int length = num_length (n);
		unsigned long i = 0;
		while (++i) {
			a = log2(n) + (length+i)*log2(10);
			b = log2(n+1) + (length+i)*log2(10);
			
			temp1 = (unsigned int)a;
			temp2 = (unsigned int)b;
			
			if (temp2 != b && temp2 - temp1 > 0) {
				cout << temp2 << endl;
				break;
			}
		}
	}
	
	return 0;
}