#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<char,char> m;

void reverse_string(string &s) {
	reverse(s.begin(), s.end());
}

string mirror_string(string b) {
	for (int i = 0, len = b.size(); i < len; i++)
		b[i] = m[b[i]];
	
	return b;
}

bool check_if_palindrome(string &a, string &b) {
	return a == b;
}

bool check_if_mirrored(string &a, string &b) {
	return a == mirror_string(b);
}

int main(void) {
	m['A'] = 'A';
	m['B'] = ' ';
	m['C'] = ' ';
	m['D'] = ' ';
	m['E'] = '3';
	m['F'] = ' ';
	m['G'] = ' ';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['K'] = ' ';
	m['L'] = 'J';
	m['M'] = 'M';
	m['N'] = ' ';
	m['O'] = 'O';
	m['P'] = ' ';
	m['Q'] = ' ';
	m['R'] = ' ';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['4'] = ' ';
	m['5'] = 'Z';
	m['6'] = ' ';
	m['7'] = ' ';
	m['8'] = '8';
	m['9'] = ' ';
	
	string input, input_r;
	bool is_palindrome, is_mirrored;
	
	while (cin >> input) {
		input_r = input;
		reverse_string(input_r);
		
		is_palindrome = check_if_palindrome(input, input_r);
		is_mirrored = check_if_mirrored(input, input_r);
		
		cout << input;
		if (is_palindrome) {
			if (is_mirrored) {
				cout << " -- is a mirrored palindrome." << endl;
			} else {
				cout << " -- is a regular palindrome." << endl;
			}
		} else if (is_mirrored) {
			cout << " -- is a mirrored string." << endl;
		} else {
			cout << " -- is not a palindrome." << endl;
		}
		
		cout << endl;
	}
	
	return 0;
}
