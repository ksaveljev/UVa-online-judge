#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main (void) {
	string input;
	char result[5];
	map<char,int> soundex;
	
	soundex['B'] = 1;
	soundex['P'] = 1;
	soundex['F'] = 1;
	soundex['V'] = 1;
	soundex['C'] = 2;
	soundex['S'] = 2;
	soundex['K'] = 2;
	soundex['G'] = 2;
	soundex['J'] = 2;
	soundex['Q'] = 2;
	soundex['X'] = 2;
	soundex['Z'] = 2;
	soundex['D'] = 3;
	soundex['T'] = 3;
	soundex['L'] = 4;
	soundex['M'] = 5;
	soundex['N'] = 5;
	soundex['R'] = 6;
	
	soundex['A'] = 0;
	soundex['E'] = 0;
	soundex['I'] = 0;
	soundex['O'] = 0;
	soundex['U'] = 0;
	soundex['Y'] = 0;
	soundex['W'] = 0;
	soundex['H'] = 0;
	
	cout << setw(13) << "NAME" << setw(33) << "SOUNDEX CODE" << endl;
	
	while (cin >> input) {
		for (int i = 0; i < 4; i++) result[i] = '0';
		
		result[0] = input[0];
		int pos = 1;
		
		for (int i = 1; i < input.size(); i++) {
			if (soundex[input[i]] > 0 && soundex[input[i]] != soundex[input[i-1]]) {
				result[pos] = '0' + soundex[input[i]];
				++pos;
				if (pos > 3)
					break;
			}
		}
		
		cout << setw(9 + input.size()) << input << setw(26 - input.size()) << result[0] << result[1] << result[2] << result[3] << endl;
	}
	
	cout << setw(19) << " ";
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}