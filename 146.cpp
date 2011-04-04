#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main (void) {
	string input;
	char buf[75];
	
	while (cin >> input) {
		if (input == "#") break;
		
		strcpy (buf, input.c_str());
		
		if (next_permutation(buf, buf + input.size()))
			cout << buf << endl;
		else
			cout << "No Successor" << endl;
	}
	
	return 0;
}