#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

int main (void) {
	vector<string> cards;
	string input;
	stack<string> stacks[13];
	map<char, int> m;
	
	m['A'] = 0;
	m['2'] = 1;
	m['3'] = 2;
	m['4'] = 3;
	m['5'] = 4;
	m['6'] = 5;
	m['7'] = 6;
	m['8'] = 7;
	m['9'] = 8;
	m['T'] = 9;
	m['J'] = 10;
	m['Q'] = 11;
	m['K'] = 12;
	
	while (cin >> input) {
		if (input == "#") break;
		
		cards.clear();
		for (int i = 0; i < 13; i++) {
			while (!stacks[i].empty())
				stacks[i].pop();
		}
		
		cards.push_back(input);
		for (int i = 0; i < 51; i++) {
			cin >> input;
			cards.push_back(input);
		}
		
		reverse (cards.begin(), cards.end());
		
		for (int i = 0; i < 52; i++) {
			stacks[i % 13].push(cards[i]);
		}
		
		int pos = 12;
		bool found = false;
		string res;
		
		int counter = 0;
		
		while (true) {
			if (stacks[pos].empty()) 
				break;
			
			res = stacks[pos].top();
			stacks[pos].pop();
			
			pos = m[res[0]];
			counter++;
		}
		
		if (counter < 10) cout << 0;
		cout << counter << "," << res << endl;
	}
	
	return 0;
}