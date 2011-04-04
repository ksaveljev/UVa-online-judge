#include <iostream>
using namespace std;

int main(void) {
	int n;
	int a, b;

	cin >> n;

	while (n--) {
		cin >> a >> b;

		if (a < b)
			cout << "<" << endl;
		else if (a > b)
			cout << ">" << endl;
		else 
			cout << "=" << endl;
	}


	return 0;
}
