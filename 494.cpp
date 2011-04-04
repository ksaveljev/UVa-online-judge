#include <iostream>
#include <string>
using namespace std;


int main (void) {
	string input;
	
	while (getline(cin, input)) {
		int counter = 0;
		bool isWord = false;
		
		for (int i = 0; i < input.size(); i++) {
			if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') {
				if (!isWord) {
					counter++;
					isWord = true;
				}
			} else {
				isWord = false;
			}
		}
		
		cout << counter << endl;
	}
	
	return 0;
}