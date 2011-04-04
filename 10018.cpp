#include <iostream>
using namespace std;

typedef unsigned long ulong;

ulong reverseNum (ulong num, ulong result) {
	if (num == 0) return result;
	else return reverseNum (num / 10, result * 10 + num % 10);
}

int main (void) {
	int n;
	ulong num;
	
	cin >> n;
	
	while (n--) {
		cin >> num;
		int counter = 0;
		
		while (num - reverseNum (num, 0) != 0) {
			counter++;
			num += reverseNum (num, 0);
		}
		
		cout << counter << " " << num << endl;
	}
	
	return 0;
}