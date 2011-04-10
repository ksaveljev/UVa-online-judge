#include <iostream>
#include <string>
#include <queue>
using namespace std;

void fill(char** map, int x, int y, int m, int n) {
	queue< pair<int,int> > q;
	
	map[x][y] = '*';
	q.push(pair<int,int>(x,y));
	
	while(!q.empty()) {
		pair<int,int> p = q.front();
		q.pop();
		
		x = p.first;
		y = p.second;
		
		if (x - 1 >= 0 && y - 1 >= 0) {
			if (map[x-1][y-1] == '@') {
				map[x-1][y-1] = '*';
				q.push(pair<int,int>(x-1, y-1));
			}
		}
		
		if (y - 1 >= 0) {
			if (map[x][y-1] == '@') {
				map[x][y-1] = '*';
				q.push(pair<int,int>(x, y-1));
			}
		}
		
		if (x - 1 >= 0) {
			if (map[x-1][y] == '@') {
				map[x-1][y] = '*';
				q.push(pair<int,int>(x-1, y));
			}
		}
		
		if (x + 1 < m && y + 1 < n) {
			if (map[x+1][y+1] == '@') {
				map[x+1][y+1] = '*';
				q.push(pair<int,int>(x+1, y+1));
			}
		}
		
		if (x + 1 < m) {
			if (map[x+1][y] == '@') {
				map[x+1][y] = '*';
				q.push(pair<int,int>(x+1, y));
			}
		}
		
		if (y + 1 < n) {
			if (map[x][y+1] == '@') {
				map[x][y+1] = '*';
				q.push(pair<int,int>(x, y+1));
			}
		}
		
		if (x - 1 >= 0 && y + 1 < n) {
			if (map[x-1][y+1] == '@') {
				map[x-1][y+1] = '*';
				q.push(pair<int,int>(x-1, y+1));
			}
		}
		
		if (x + 1 < m && y - 1 >= 0) {
			if (map[x+1][y-1] == '@') {
				map[x+1][y-1] = '*';
				q.push(pair<int,int>(x+1, y-1));
			}
		}
	}
}

int main(void) {
	int m, n;
	int result;
	string line;
	char **map;
	
	while (cin >> m >> n) {
		if (m == 0) break;
		
		map = new char*[m];
		
		for (int i = 0; i < m; i++)
			map[i] = new char[n];
		
		
		getline(cin, line); // \n
		for (int i = 0; i < m; i++) {
			getline(cin, line);
			for (int y = 0; y < n; y++) {
				map[i][y] = line[y];
			}
		}
		
		
		result = 0;
		
		for (int i = 0; i < m; i++) {
			for (int y = 0; y < n; y++) {
				if (map[i][y] == '@') {
					fill(map, i, y, m, n);
					result++;
				}
			}
		}
		
		cout << result << endl;
		
		
		for (int i = 0; i < m; i++)
			delete[] map[i];
		
		delete[] map;
	}
	
	return 0;
}
