#include <iostream>
using namespace std;

int main (void) {
	unsigned int a, b;
	
	while (cin >> a >> b) {
		unsigned int res = a ^ b;
		cout << res << endl;
	}
	
	return 0;
}