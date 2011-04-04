#include <iostream>
#include <vector>
using namespace std;

int main (void) {
	char c, v;
	bool newvertex = true;
	vector<char> moves[26]; // for each cavern there is a list of reachable caverns
						// and it is listed in order that the Minotaur will attempt them

	
	while (c = getchar()) {
		if (c == '#') break;
		
		if (c >= 'A' && c <= 'Z' && newvertex == true) {
			v = c;
			newvertex = false;
			c = getchar(); // reading ':'
		} else if (c >= 'A' && c <= 'Z' && newvertex == false) {
			moves[v-65].push_back(c);
		} else if (c == ';') {
			newvertex = true;
		} else if (c == '.') {
			newvertex = true;
			
			char mstart;
			bool mfound = false;
			char tstart;
			int k = 0;
			
			while (c = getchar()) {
				if (c == '\n') break;
				
				if (c >= 'A' && c <= 'Z' && mfound == false) {
					mfound = true;
					mstart = c;
				} else if (c >= 'A' && c <= 'Z' && mfound == true) {
					tstart = c;
				} else if (c >= '0' && c <= '9') {
					k = k * 10 + c - 48;
				}
			}
			
			// start the movement of Theseus and the Minotaur
			char prev = tstart;
			int temp = 0; // how many moves where made - we need it to "set up candles"
			while (true) {
				if (moves[mstart-65].size() == 0) {
					cout << "/" << mstart << endl;
					break;
				} else if (moves[mstart-65].size() == 1 && moves[mstart-65][0] == prev) {
					cout << "/" << mstart << endl;
					break;
				} else {
					if (moves[mstart-65][0] != prev) {
						prev = mstart;
						mstart = moves[mstart-65][0];
					} else {
						prev = mstart;
						mstart = moves[mstart-65][1];
					}
						
					
					//cout << "MINOTAUR MOVES TO: " << mstart << endl;
					//cout << "AVAILABLE MOVES: ";
					//for (int i = 0; i < moves[mstart-65].size(); i++)
					//	cout << moves[mstart-65][i] << " ";
					//cout << endl;
					++temp;
					
					if (temp == k) {
						cout << prev << " ";
						temp = 0;
						moves[prev-65].clear();
						
						for (int i = 0; i < 26; i++) {
							for (vector<char>::iterator it = moves[i].begin(); it != moves[i].end(); it++) {
								if ((*it) == prev) {
									moves[i].erase(it);
									break;
								}
							}
						}
					}
				}
			}
			
			for (int i = 0; i < 26; i++)
				moves[i].clear();
				
			newvertex = true;
		}
	}
	
	return 0;
}