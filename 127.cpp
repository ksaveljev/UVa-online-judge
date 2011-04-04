#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int main (void) {
	map<char,int> stats;
	
	stats['2'] = 2;
	stats['3'] = 3;
	stats['4'] = 4;
	stats['5'] = 5;
	stats['6'] = 6;
	stats['7'] = 7;
	stats['8'] = 8;
	stats['9'] = 9;
	stats['T'] = 10;
	stats['J'] = 11;
	stats['Q'] = 12;
	stats['K'] = 13;
	stats['A'] = 14;
	stats['S'] = 20;
	stats['H'] = 30;
	stats['D'] = 40;
	stats['C'] = 50;
	
	
	string input;
	vector< pair<int,int> > cards;
	stack< pair<int,int> > piles[52];
	
	while (cin >> input) {
		if (input == "#") break;
		
		cards.clear();
		for (int i = 0; i < 52; i++) {
			while (!piles[i].empty())
				piles[i].pop();
		}
		
		cards.push_back (pair<int,int>(stats[input[0]], stats[input[1]]));
		for (int i = 0; i < 51; i++) {
			cin >> input;
			cards.push_back (pair<int,int>(stats[input[0]], stats[input[1]]));
		}
		
		
		int pos = 0;
		bool ended = false;
		
		while (!cards.empty()) {
			piles[pos].push (cards[0]);
			cards.erase (cards.begin());
			++pos;
			
			bool mademove = true;
			while (mademove) {
				mademove = false;
				for (int i = 0; i < pos; i++) {
					if (i - 3 >= 0) {
						if (piles[i].top().first == piles[i-3].top().first || piles[i].top().second == piles[i-3].top().second) {
							piles[i-3].push (piles[i].top());
							piles[i].pop();
							mademove = true;
							break;
						}
					} 
					if (i - 1 >= 0) {
						if (piles[i].top().first == piles[i-1].top().first || piles[i].top().second == piles[i-1].top().second) {
							piles[i-1].push (piles[i].top());
							piles[i].pop();
							mademove = true;
							break;
						}
					}
				}
				
				if (mademove == true) {
					for (int i = 0; i < pos; i++) {
						if (piles[i].empty()) {
							if (i == pos - 1) {
								--pos;
							} else {
								for (int j = i + 1; j < pos; j++) {
									swap (piles[j], piles[j-1]);
								}
								--pos;
							}
							
							break;
						}
					}
				}
			}
		}
		
		cout << pos;
		if (pos == 1)
			cout << " pile remaining:";
		else
			cout << " piles remaining:";

		for (int i = 0; i < pos; i++)
			cout << " " << piles[i].size();
		cout << endl;
	}
	
	return 0;
}