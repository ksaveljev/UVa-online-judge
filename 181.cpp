#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

map<char,int> denominations;

bool theTruthIsOutThere(string a, string b) {
	if (denominations[a[0]] > denominations[b[0]])
		return true;
	else if (denominations[a[0]] == denominations[b[0]]) {
		if (a[1] == 'S')
			return true;
		else if (b[1] == 'S')
			return false;
		else if (a[1] == 'H')
			return true;
		else if (b[1] == 'H')
			return false;
		else if (a[1] == 'D')
			return true;
		else if (b[1] == 'D')
			return false;
	}
	else
		return false;
}

int main (void) {
	vector<string> cards;
	string input;
	vector<string> players[5];
	vector<string> result[5];
	char trump;
	vector<string> step;
	
	denominations['2'] = 2;
	denominations['3'] = 3;
	denominations['4'] = 4;
	denominations['5'] = 5;
	denominations['6'] = 6;
	denominations['7'] = 7;
	denominations['8'] = 8;
	denominations['9'] = 9;
	denominations['T'] = 10;
	denominations['J'] = 11;
	denominations['Q'] = 12;
	denominations['K'] = 13;
	denominations['A'] = 14;
	
	while (cin >> input) {
		if (input == "#") break;
		
		cards.clear();
		for (int i = 0; i < 5; i++)
			result[i].clear();
		
		cards.push_back(input);
		for (int i = 0; i < 51; i++) {
			cin >> input;
			cards.push_back(input);
		}
		
		for (int i = 0; i < 50; i++) {
			players[i % 5].push_back(cards[i]);
		}

		
		// find the trump from 2 remaining cards
		if (denominations[cards[50][0]] < denominations[cards[51][0]]) {
			trump = cards[51][1];
		} else if (denominations[cards[50][0]] > denominations[cards[51][0]]) {
			trump = cards[50][1];
		} else {
			// S H D C
			if (cards[50][1] == 'S' || cards[51][1] == 'S')
				trump = 'S';
			else if (cards[50][1] == 'H' || cards[51][1] == 'H')
				trump = 'H';
			else if (cards[50][1] == 'D' || cards[51][1] == 'D')
				trump = 'D';
			else
				trump = 'C';
		}

		// sort all players' cards
		for (int i = 0; i < 5; i++) {
			sort (players[i].begin(), players[i].end(), theTruthIsOutThere);
		}
		
		// who's turn it is to start
		int player = 0; // 0 means the one to the left of the dealer
		pair<string,int> best;
		string first = "";
		string taken;
		
		// the game begins
		for (int i = 0; i < 10; i++) {
			step.clear();
			int current;
			
			first = players[player][0];
			
			best.first = players[player][0];
			best.second = player;
			
			// removing this card from player's stack
			players[player].erase(players[player].begin());
		
			
			step.push_back(first);
			
			// for each player
			for (int j = 1; j < 5; j++) {
				current = player + j;
				if (current > 4) current = current % 5;
				
				bool found = false;
				
				// searching if this player has a card of the same suit
				for (int k = 0; k < players[current].size(); k++) {
					if (players[current][k][1] == first[1]) {
						found = true;
						taken = players[current][k];
						step.push_back(players[current][k]);
						players[current].erase(players[current].begin() + k);
						break;
					}
				}
				
				// so there is no card of the same suit
				// trying to find the biggest trump
				if (!found) {
					for (int k = 0; k < players[current].size(); k++) {
						if (players[current][k][1] == trump) {
							found = true;
							taken = players[current][k];
							step.push_back(players[current][k]);
							players[current].erase(players[current].begin() + k);
							break;
						}
					}
				}
				
				// this player has no card of the needed suit and no trumps
				// which leaves the only solution - give up the biggest hand
				if (!found) {
					found = true;
					taken = players[current][0];
					step.push_back(players[current][0]);
					players[current].erase(players[current].begin());
				}
				
				// now after this step we need to determine the player
				// who is currently winning this stack...
				if (taken[1] == best.first[1]) { // if the suit is the same
					if (denominations[taken[0]] > denominations[best.first[0]]) {
						best.first = taken;
						best.second = current;
					}
				} else if (taken[1] == trump) { // if it is the first trump during this step
					best.first = taken;
					best.second = current;
				}
			}

			
			// now we have the winner and save the results of the step
			for (int p = 0; p < step.size(); p++) {
				result[best.second].push_back(step[p]);
			}
			
			player = best.second;
		}
		
		// now we have played the game and can count the results
		int temp = 4;
		for (int i = 0; i < 5; i++) {
			int sum = 0;
			for (int j = 0; j < result[(temp + i) % 5].size(); j++) {
				if (result[(temp+i) % 5][j][1] == 'H') {
					sum += denominations[result[(temp+i) % 5][j][0]];
				}
			}
			cout << setw(3) << sum;
		}
		cout << endl;
	}
	
	
	return 0;
}