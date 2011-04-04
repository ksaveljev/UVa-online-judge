#include <iostream>
#include <queue>
#include <map>
using namespace std;

char dungeon[30][30][30];
int l, r, c;

pair< int, pair<int,int> > moves[] = { 	pair< int, pair<int,int> >(0, pair<int,int>(-1, 0)),
	 									pair< int, pair<int,int> >(0, pair<int,int>(1, 0)),
	 									pair< int, pair<int,int> >(0, pair<int,int>(0, -1)),
										pair< int, pair<int,int> >(0, pair<int,int>(0, 1)),
										pair< int, pair<int,int> >(1, pair<int,int>(0, 0)),
										pair< int, pair<int,int> >(-1, pair<int,int>(0,0))};

struct coord {
	int level;
	int row;
	int column;
};

typedef struct coord coordinates;

int bfs (coordinates start) {
	queue< pair<coordinates, int> > next;
	bool visited[30][30][30];
	
	memset (visited, false, sizeof visited);
	
	next.push(pair<coordinates,int>(start,0));
	visited[start.level][start.row][start.column] = true;
	
	while (!next.empty()) {
		pair<coordinates,int> u = next.front();
		next.pop();
		
		if (dungeon[u.first.level][u.first.row][u.first.column] == 'E') return u.second;
		
		for (int i = 0; i < 6; i++) {
			if (u.first.level + moves[i].first >= 0 && u.first.level + moves[i].first < l && u.first.row + moves[i].second.first >= 0 && u.first.row + moves[i].second.first < r && u.first.column + moves[i].second.second >= 0 && u.first.column + moves[i].second.second < c && dungeon[u.first.level + moves[i].first][u.first.row + moves[i].second.first][u.first.column + moves[i].second.second] != '#' && visited[u.first.level + moves[i].first][u.first.row + moves[i].second.first][u.first.column + moves[i].second.second] == false) {
				coordinates temp;
				temp.level = u.first.level + moves[i].first;
				temp.row = u.first.row + moves[i].second.first;
				temp.column = u.first.column + moves[i].second.second;
				next.push(pair<coordinates,int>(temp, u.second + 1));
				visited[temp.level][temp.row][temp.column] = true;
			}
		}
	}

	return -1;
}

int main (void) {
	while (cin >> l >> r >>c) {
		if (l == 0 && r == 0 && c == 0) break;
		coordinates start;
		
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++) {
					cin >> dungeon[i][j][k];
					if (dungeon[i][j][k] == 'S') {
						start.level = i;
						start.row = j;
						start.column = k;
					}
				}

		
		int result = bfs (start);
		
		if (result == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << result << " minute(s)." << endl;
	}
	
	return 0;
}