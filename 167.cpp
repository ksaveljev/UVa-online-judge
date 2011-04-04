#include <iostream>
#include <queue>
using namespace std;

bool board[8][8];
int score[8][8];
int maximum;

void theTruthIsOutThere(int n, int m) {
	if (n == 8) {
		if (m > maximum) maximum = m;
		return;
	}
	
	vector< pair<int,int> > taken;
	for (int i = 0; i < 8; i++) {
		if (board[n][i] == true) {
			m += score[n][i];
			
			for (int j = 0; j < 8; j++) {
				if (board[n][j] == true) {
					board[n][j] = false;
					taken.push_back(pair<int,int>(n, j));
				}
				if (board[j][i] == true) {
					board[j][i] = false;
					taken.push_back(pair<int,int>(j, i));
				}
			}
			
			int a = n - 1, b = i - 1;
			while (a >= 0 && b >= 0) {
				if (board[a][b] == true) {
					board[a][b] = false;
					taken.push_back(pair<int,int>(a, b));
				}
				a--; b--;
			}
			
			a = n + 1; b = i + 1;
			while (a < 8 && b < 8) {
				if (board[a][b] == true) {
					board[a][b] = false;
					taken.push_back(pair<int,int>(a, b));
				}
				a++; b++;
			}
			
			a = n + 1; b = i - 1;
			while (a < 8 && b >= 0) {
				if (board[a][b] == true) {
					board[a][b] = false;
					taken.push_back(pair<int,int>(a, b));
				}
				a++; b--;
			}
			
			a = n - 1; b = i + 1;
			while (a >= 0 && b < 8) {
				if (board[a][b] == true) {
					board[a][b] = false;
					taken.push_back(pair<int,int>(a, b));
				}
				a--; b++;
			}
			
			
			theTruthIsOutThere(n + 1, m);
			
			
			for (int j = 0; j < taken.size(); j++) {
				board[taken[j].first][taken[j].second] = true;
			}
			
			m -= score[n][i];
		}
	}
	
	return;
}

int main (void) {
	int n;
	
	cin >> n;
	
	while (n--) {
		maximum = 0;
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> score[i][j];
				board[i][j] = true;
			}
		}
		
		theTruthIsOutThere(0, 0);
		
		cout.width(5);
		cout << maximum << endl;
	}
	
	return 0;
}