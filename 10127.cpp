#include <iostream>
using namespace std;

int main (void) {
	int n;
	
	while (cin >> n) {
		int counter = 1;
		int temp = 1;
		while (temp%n) {
			temp %= n;
			temp = temp * 10 + 1;
			counter++;
		}
		
		cout << counter << endl;
	}
	
	return 0;
}