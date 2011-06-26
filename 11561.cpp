#include <iostream>
#include <queue>
using namespace std;

char maze[51][51];
bool visited[51][51];

bool can_move(pair<int,int> pos)
{
  return maze[pos.first-1][pos.second] != 'T' && maze[pos.first+1][pos.second] != 'T' && maze[pos.first][pos.second-1] != 'T' && maze[pos.first][pos.second+1] != 'T';
}

int solve(pair<int,int> start)
{
  int result = 0;
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  for (int i = 0; i < 51; i++) {
    for (int j = 0; j < 51; j++) {
      visited[i][j] = false;
    }
  }

  q.push(start);
  visited[start.first][start.second] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (maze[tmp.first][tmp.second] == 'G') {
      result++;
    }

    if (!can_move(tmp)) {
      continue;
    }

    if (!visited[tmp.first-1][tmp.second] && maze[tmp.first-1][tmp.second] != '#') {
      visited[tmp.first-1][tmp.second] = true;
      q.push(make_pair(tmp.first-1, tmp.second));
    }

    if (!visited[tmp.first+1][tmp.second] && maze[tmp.first+1][tmp.second] != '#') {
      visited[tmp.first+1][tmp.second] = true;
      q.push(make_pair(tmp.first+1, tmp.second));
    }

    if (!visited[tmp.first][tmp.second-1] && maze[tmp.first][tmp.second-1] != '#') {
      visited[tmp.first][tmp.second-1] = true;
      q.push(make_pair(tmp.first, tmp.second-1));
    }

    if (!visited[tmp.first][tmp.second+1] && maze[tmp.first][tmp.second+1] != '#') {
      visited[tmp.first][tmp.second+1] = true;
      q.push(make_pair(tmp.first, tmp.second+1));
    }
  }

  return result;
}

int main(void)
{
  int col, row;
  pair<int,int> start;

  while (cin >> col >> row) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> maze[i][j];

        if (maze[i][j] == 'P') {
          start.first = i;
          start.second = j;
          maze[i][j] = '.';
        }
      }
    }

    cout << solve(start) << endl;
  }

  return 0;
}
