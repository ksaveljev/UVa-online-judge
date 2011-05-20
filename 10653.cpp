#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
char board[1000][1000];
bool visited[1000][1000];
typedef pair<int,int> pos;

int bfs(const pos &start, const pos &end) {
  pair<pos, int> tmp;
  queue< pair<pos,int> > q;

  tmp.first = start;
  tmp.second = 0;
  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first == end)
      return tmp.second;

    if (tmp.first.first >= 1 && !visited[tmp.first.first-1][tmp.first.second] && board[tmp.first.first-1][tmp.first.second] != '*') {
      visited[tmp.first.first-1][tmp.first.second] = true;
      q.push(make_pair(make_pair(tmp.first.first-1, tmp.first.second), tmp.second + 1));
    }

    if (tmp.first.first + 1 < r && !visited[tmp.first.first+1][tmp.first.second] && board[tmp.first.first+1][tmp.first.second] != '*') {
      visited[tmp.first.first+1][tmp.first.second] = true;
      q.push(make_pair(make_pair(tmp.first.first+1, tmp.first.second), tmp.second + 1));
    }

    if (tmp.first.second >= 1 && !visited[tmp.first.first][tmp.first.second-1] && board[tmp.first.first][tmp.first.second-1] != '*') {
      visited[tmp.first.first][tmp.first.second-1] = true;
      q.push(make_pair(make_pair(tmp.first.first, tmp.first.second-1), tmp.second + 1));
    }

    if (tmp.first.second + 1 < c && !visited[tmp.first.first][tmp.first.second+1] && board[tmp.first.first][tmp.first.second+1] != '*') {
      visited[tmp.first.first][tmp.first.second+1] = true;
      q.push(make_pair(make_pair(tmp.first.first, tmp.first.second+1), tmp.second + 1));
    }
  }

  return -1;
}

int main(void) {
  pos start, end;
  int rows, row, n, col;

  while (cin >> r >> c) {
    if (r == 0 && c == 0)
      break;

    for (int i = 0; i < 1000; i++) {
      fill(board[i], board[i] + 1000, ' ');
      fill(visited[i], visited[i] + 1000, false);
    }

    cin >> rows;

    while (rows--) {
      cin >> row >> n;

      while (n--) {
        cin >> col;
        board[row][col] = '*';
      }
    }

    cin >> start.first >> start.second;
    cin >> end.first >> end.second;

    cout << bfs(start, end) << endl;
  }

  return 0;
}
