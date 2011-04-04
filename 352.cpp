#include <iostream>
#include <string>
#include <queue>
using namespace std;

void fill(int m[25][25], int i, int y, int n) {
	pair<int,int> tmp;
	queue< pair<int,int> > q;

	q.push(make_pair(i,y));

	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		
		m[tmp.first][tmp.second] = 0;

		if (tmp.first - 1 >= 0 && m[tmp.first-1][tmp.second] == 1) {
			m[tmp.first-1][tmp.second] = 0;
			q.push(make_pair(tmp.first-1, tmp.second));
		}
		if (tmp.second - 1 >= 0 && m[tmp.first][tmp.second-1] == 1) {
			m[tmp.first][tmp.second-1] = 0;
			q.push(make_pair(tmp.first, tmp.second-1));
		}
		if (tmp.first - 1 >= 0 && tmp.second - 1 >= 0 && m[tmp.first-1][tmp.second-1] == 1) {
			m[tmp.first-1][tmp.second-1] = 0;
			q.push(make_pair(tmp.first-1, tmp.second-1));
		}
		if (tmp.first + 1 < n && m[tmp.first+1][tmp.second] == 1) {
			m[tmp.first+1][tmp.second] = 0;
			q.push(make_pair(tmp.first+1, tmp.second));
		}
		if (tmp.second + 1 < n && m[tmp.first][tmp.second+1] == 1) {
			m[tmp.first][tmp.second+1] = 0;
			q.push(make_pair(tmp.first, tmp.second+1));
		}
		if (tmp.first + 1 < n && tmp.second + 1 < n && m[tmp.first+1][tmp.second+1] == 1) {
			m[tmp.first+1][tmp.second+1] = 0;
			q.push(make_pair(tmp.first+1, tmp.second+1));
		}
		if (tmp.first - 1 >= 0 && tmp.second + 1 < n && m[tmp.first-1][tmp.second+1] == 1) {
			m[tmp.first-1][tmp.second+1] = 0;
			q.push(make_pair(tmp.first-1, tmp.second+1));
		}
		if (tmp.first + 1 < n && tmp.second - 1 >= 0 && m[tmp.first+1][tmp.second-1] == 1) {
			m[tmp.first+1][tmp.second-1] = 0;
			q.push(make_pair(tmp.first+1, tmp.second-1));
		}
	}
}

int main(void) {
	int n;
	int counter;
	string line;
	int m[25][25];
	int casenum = 0;

	while (cin >> n) {
		counter = 0;
		casenum++;

		for (int i = 0; i < n; i++) {
			cin >> line;
			for (int y = 0; y < n; y++) {
				m[i][y] = line[y] == '0' ? 0 : 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int y = 0; y < n; y++) {
				if (m[i][y] == 1) {
					counter++;
					fill(m, i, y, n);
				}
			}
		}

		cout << "Image number " << casenum << " contains " << counter << " war eagles." << endl;
	}

	return 0;
}
