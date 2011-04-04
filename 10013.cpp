#include <iostream>
using namespace std;

int main (void) {
	char* result = new char[1000002];
	int n, m, pos, carry, counter = 0;
	char a, b;
	
	cin >> n;
	
	while (n--) {
		counter++;
		cin >> m;
		pos = 0;
		
		result[pos] = (char) 0;
		
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			++pos;
			result[pos] = a - '0' + b - '0';
		}
		
		carry = 0;
		char temp;
		for (int i = pos; i >= 0; i--) {
			temp = result[i];
			result[i] = (carry + temp) % 10;
			carry = (carry + temp) / 10;
		}
		
		if (counter > 1) cout << endl;
		for (int i = 0; i <= pos; i++) {
			if (i == 0) {
				if((int)result[i] > 0) 
					cout << (char) (result[i] + '0');
			} else {
				cout << (char) (result[i] + '0');
			}
		}
		cout << endl;
	}
	
	
	delete result;
	
	return 0;
}