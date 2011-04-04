#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main(void) {
	int t;
	char c;
	string input;
	map<string, char> m;

	m[".-"]		= 'A';
	m["-..."]	= 'B';
	m["-.-."]	= 'C';
	m["-.."]	= 'D';
	m["."]		= 'E';
	m["..-."]	= 'F';
	m["--."]	= 'G';
	m["...."]	= 'H';
	m[".."]		= 'I';
	m[".---"]	= 'J';
	m["-.-"]	= 'K';
	m[".-.."]	= 'L';
	m["--"]		= 'M';
	m["-."]		= 'N';
	m["---"]	= 'O';
	m[".--."]	= 'P';
	m["--.-"]	= 'Q';
	m[".-."]	= 'R';
	m["..."]	= 'S';
	m["-"]		= 'T';
	m["..-"]	= 'U';
	m["...-"]	= 'V';
	m[".--"]	= 'W';
	m["-..-"]	= 'X';
	m["-.--"]	= 'Y';
	m["--.."]	= 'Z';
	m["-----"]	= '0';
	m[".----"]	= '1';
	m["..---"]	= '2';
	m["...--"]	= '3';
	m["....-"]	= '4';
	m["....."]	= '5';
	m["-...."]	= '6';
	m["--..."]	= '7';
	m["---.."]	= '8';
	m["----."]	= '9';
	m[".-.-.-"] = '.';
	m["--..--"] = ',';
	m["..--.."] = '?';
	m[".----."] = '\'';
	m["-.-.--"] = '!';
	m["-..-."]	= '/';
	m["-.--."]	= '(';
	m["-.--.-"] = ')';
	m[".-..."]	= '&';
	m["---..."] = ':';
	m["-.-.-."] = ';';
	m["-...-"]	= '=';
	m[".-.-."]	= '+';
	m["-....-"] = '-';
	m["..--.-"] = '_';
	m[".-..-."] = '"';
	m[".--.-."] = '@';

	cin >> t;

	getline(cin, input); // \n
	for (int cases = 0; cases < t; cases++) {
		if (cases > 0)
			cout << endl;
		cout << "Message #" << cases+1 << endl;

		getline(cin, input);
		stringstream ss;
		ss << input;

		while (ss >> input) {
			//if (ss.good())
			//	cout << "ss is still good" << endl;
			//else
			//	cout << "ss is NOT good" << endl;
			//c = ss.peek();
			//cout << "peek() char = " << c << endl;
			//ss.get(c);
			//if (ss.good())
			//	cout << "ss is STILL good" << endl;
			//else
			//	cout << "ss is DEFINETLY NOT good" << endl;
			//c = ss.peek();
			//cout << "peek() next char = " << c << endl;
			cout << m[input];
			if (ss.good()) {
				c = ss.get();
				c = ss.peek();
				if (c == ' ')
					cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
