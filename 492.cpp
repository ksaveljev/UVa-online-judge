#include <iostream>
using namespace std;

int main (void) {
	char c;
	char consonant = ' ';
	bool first = true;
	char vowel[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
	string toappend = "ay";
	
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			if (first) {
				bool found = false;
				for (int i = 0; i < 10; i++) {
					if (vowel[i] == c) {
						found = true;
						break;
					}
				}
				
				if (!found) {
					consonant = c;
				} else {
					consonant = ' ';
					cout << c;
				}
				
				first = false;
			} else {
				cout << c;
			}
		} else {
			if (!first) {
				if (consonant != ' ')
					cout << consonant;
				
				consonant = ' ';
				cout << toappend;
			}
			
			first = true;
			cout << c;
		}
	}
	
	return 0;
}