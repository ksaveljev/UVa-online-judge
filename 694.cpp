#include <iostream>
using namespace std;

typedef unsigned long llong;

int main (void) {
	llong a, limit;
	llong aoutput, limitoutput;
	
	int c = 0;
	
	while (cin >> a >> limit) {
		if (a < 0 && limit < 0) break;
		aoutput = a;
		limitoutput = limit;
		
		++c;
		
		int counter = 0;
		do {
			++counter;
			if (a == 1) break;
			else if ( a % 2 == 0 ) a /= 2;
			else a = 3 * a + 1;
		} while (a <= limit);
		
		cout << "Case " << c << ": A = " << aoutput << ", limit = " << limitoutput << ", number of terms = " << counter << endl;
	}
	
	return 0;
}