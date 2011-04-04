#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (void) {
	int x,y;
	int counter = 0;
	
	while (cin >> x) {
		if (x == 0) break;
		cin >> y;
		
		++counter;
		
		string input;
		char crossword[x][y];
		int num[x][y];
		
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				num[i][j] = 0;
		
		for (int i = 0; i < x; i++) {
			cin >> input;
			for (int j = 0; j < y; j++)
				crossword[i][j] = input[j];
		}
		
		
		int c = 1;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (crossword[i][j] != '*') {
					if (j - 1 < 0 || crossword[i][j-1] == '*') {
						num[i][j] = c;
						++c;
					} else if (i - 1 < 0 || crossword[i-1][j] == '*') {
						num[i][j] = c;
						++c;
					}
				}
			}
		}
		
		
	
		if (counter > 1) cout << endl;
		
		cout << "puzzle #" << counter << ":" << endl;
		cout << "Across" << endl;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (num[i][j] > 0) {
					if (j-1 < 0 || crossword[i][j-1] == '*') {
						cout << setw(3) << num[i][j] << ".";
						
						for (int k = j; k < y; k++) {
							if (crossword[i][k] == '*') break;
							cout << crossword[i][k];
						}
						
						cout << endl;
					}
				}
			}
		}
		
		cout << "Down" << endl;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if (num[i][j] > 0) {
					if (i-1 < 0 || crossword[i-1][j] == '*') {
						cout << setw(3) << num[i][j] << ".";
						
						for (int k = i; k < x; k++) {
							if (crossword[k][j] == '*') break;
							cout << crossword[k][j];
						}
						
						cout << endl;
					}
				}
			}
		}
	}
	
	return 0;
}