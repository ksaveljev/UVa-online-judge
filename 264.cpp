#include <iostream>
using namespace std;

int main (void) {
	int n;
	
	while (cin >> n) {
		if (n == 1) { cout << "TERM 1 IS 1/1" << endl; continue; }
		
		int line = 2;
		int elements = (1 + line) * line / 2;
		
		while (elements < n) {
			++line;
			elements = (1 + line) * line / 2;
		}
		
		int temp = n - (1 + (line-1)) * (line-1) / 2;
		if (line % 2 != 0) {
			cout << "TERM " << n << " IS " << line - (temp-1) << "/" << temp << endl;
		} else {
			cout << "TERM " << n << " IS " << temp << "/" << line - (temp-1) << endl;
		}
	}
	
	return 0;
}