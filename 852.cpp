#include <iostream>
#include <string>
#include <queue>
using namespace std;

char board[9][9];

void fill(int x, int y, char c) {
  board[x][y] = c;

  if (x > 0 && board[x-1][y] == '.')
    fill(x-1, y, c);

  if (y > 0 && board[x][y-1] == '.')
    fill(x, y-1, c);

  if (x+1 < 9 && board[x+1][y] == '.')
    fill(x+1, y, c);

  if (y+1 < 9 && board[x][y+1] == '.')
    fill(x, y+1, c);
}

int try_and_fill(int x, int y) {
  char c = ' ';
  bool visited[9][9];
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      visited[i][j] = false;

  tmp.first = x;
  tmp.second = y;
  q.push(tmp);

  visited[x][y] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0 && !visited[tmp.first-1][tmp.second]) {
      if (board[tmp.first-1][tmp.second] == '.') {
        visited[tmp.first-1][tmp.second] = true;
        q.push(make_pair(tmp.first-1, tmp.second));
      } else {
        if (c == ' ') { 
          c = board[tmp.first-1][tmp.second];
        } else {
          if (c != board[tmp.first-1][tmp.second])
            return -1;
        }
      }
    }

    if (tmp.second > 0 && !visited[tmp.first][tmp.second-1]) {
      if (board[tmp.first][tmp.second-1] == '.') {
        visited[tmp.first][tmp.second-1] = true;
        q.push(make_pair(tmp.first, tmp.second-1));
      } else {
        if (c == ' ')
          c = board[tmp.first][tmp.second-1];
        else
          if (c != board[tmp.first][tmp.second-1])
            return -1;
      }
    }

    if (tmp.first + 1 < 9 && !visited[tmp.first+1][tmp.second]) {
      if (board[tmp.first+1][tmp.second] == '.') {
        visited[tmp.first+1][tmp.second] = true;
        q.push(make_pair(tmp.first+1, tmp.second));
      } else {
        if (c == ' ')
          c = board[tmp.first+1][tmp.second];
        else
          if (c != board[tmp.first+1][tmp.second])
            return -1;
      }
    }

    if (tmp.second + 1 < 9 && !visited[tmp.first][tmp.second+1]) {
      if (board[tmp.first][tmp.second+1] == '.') {
        visited[tmp.first][tmp.second+1] = true;
        q.push(make_pair(tmp.first, tmp.second+1));
      } else {
        if (c == ' ')
          c = board[tmp.first][tmp.second+1];
        else
          if (c != board[tmp.first][tmp.second+1])
            return -1;
      }
    }
  }

  switch (c) {
    case ' ':
      return -1;
      break;
    case 'X':
      return 0;
      break;
    case 'O':
      return 1;
      break;
  }
}

int main(void) {
  int cases;
  string input;

  cin >> cases;
  cin.ignore(100, '\n');

  while (cases--) {
    for (int i = 0; i < 9; i++) {
      getline(cin, input);
      for (int j = 0; j < 9; j++)
        board[i][j] = input[j];
    }

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.')
          continue;

        int result = try_and_fill(i, j); // -1: can't, 0 - X, 1 - O
        switch (result) {
          case -1:
            fill(i, j, '*');
            break;
          case 0:
            fill(i, j, 'X');
            break;
          case 1:
            fill(i, j, 'O');
            break;
        }
      }
    }

    int whites = 0;
    int blacks = 0;

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == 'X')
          blacks++;
        else if (board[i][j] == 'O')
          whites++;
      }
    }

    cout << "Black " << blacks << " White " << whites << endl;
  }

  return 0;
}
