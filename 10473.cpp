#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
	unsigned int num;
	string input;

	while (cin >> input) {
		if (input[0] == '-')
			break;
		
		istringstream ss;

		ss.str(input);

		if (input.size() > 1 && input[1] == 'x') {
			ss >> hex >> num;
			cout << dec << num << endl;
		} else {
			ss >> dec >> num;
			cout << "0x" <<  uppercase << hex << num << endl;
		}
	}

	return 0;
}
