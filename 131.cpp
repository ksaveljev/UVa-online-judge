#include <iostream>
#include <string>
#include <map>
using namespace std;

int cards[10][2];
map<char, int> deck;

void process_card (string card, int n) {
	cards[n][0] = deck[card[0]];
	cards[n][1] = deck[card[1]];
}

int main (void) {
	string input;
	
	deck['2'] = 2;
	deck['3'] = 3;
	deck['4'] = 4;
	deck['5'] = 5;
	deck['6'] = 6;
	deck['7'] = 7;
	deck['8'] = 8;
	deck['9'] = 9;
	deck['T'] = 10;
	deck['J'] = 11;
	deck['Q'] = 12;
	deck['K'] = 13;
	deck['A'] = 14;
	
	deck['H'] = 1;
	deck['C'] = 2;
	deck['D'] = 3;
	deck['S'] = 4;
	
	while (cin >> input) {
		process_card (input, 0);
		for (int i = 1; i < 10; i++) {
			cin >> input;
			process_card (input, i);
		}
	}
	
	return 0;
}