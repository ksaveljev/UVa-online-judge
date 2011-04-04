#include <iostream>
#include <string>
#include <queue>
using namespace std;

char maze[30][80];
int x, y;

void bfs() {
	queue< pair<int,int> > q;
	q.push (pair<int,int>(x,y));
	
	while (!q.empty()) {
		int x1 = q.front().first, y1 = q.front().second;
		q.pop();
		maze[x1][y1] = '#';
		
		if (x1-1 >= 0 && maze[x1-1][y1] == ' ') {
			maze[x1-1][y1] = '#';
			q.push (pair<int,int>(x1-1,y1));
		}
		if (x1 + 1 < 30 && maze[x1+1][y1] == ' ') {
			maze[x1+1][y1] = '#';
			q.push (pair<int,int>(x1+1,y1));
		}
		if (y1-1 >= 0 && maze[x1][y1-1] == ' ') {
			maze[x1][y1-1] = '#';
			q.push (pair<int,int>(x1,y1-1));
		}
		if (y1+1 < 80 && maze[x1][y1+1] == ' ') {
			maze[x1][y1+1] = '#';
			q.push (pair<int,int>(x1,y1+1));
		}
	}
}

int main (void) {
	string input;
	int n, counter;
	
	cin >> n;
	getline (cin, input);
	
	while (n--) {
		for (int i = 0; i < 30; i++)
			for (int j = 0; j < 80; j++)
				maze[i][j] = 'e';
				
		counter = 0;
		
		while (getline(cin,input)) {
			if (input[0] == '_') {
				bfs();
				for (int i = 0; i < 30; i++) {
					for (int j = 0; j < 80; j++) {
						if (maze[i][j] == 'e') break;
						cout << maze[i][j];
					}
					if (maze[i][0] == 'e') break;
					cout << endl;
				}
				cout << input << endl;
				break;
			} else {
				for (int i = 0; i < input.size(); i++) {
					if (input[i] == '*') {
						x = counter;
						y = i;
					}
					maze[counter][i] = input[i];
				}
			}
			counter++;
		}
	}
	
	
	return 0;
}