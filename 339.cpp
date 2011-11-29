#include <iostream>
#include <queue>
using namespace std;

int R, C;
// 0 - 9: field has a value of specified int
// -1: emptied value
int board[10][40];

void clear_board() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 40; j++) {
      board[i][j] = -1;
    }
  }
}

bool removable(int row, int col) {
  if (row > R || row < 1 || col > C || col < 1) {
    return false;
  }

  row = R - row;
  col = col - 1;

  if (board[row][col] == -1) {
    return false;
  }

  int v = board[row][col];

  if (row > 0 && board[row-1][col] == v || col > 0 && board[row][col-1] == v || row + 1 < R && board[row+1][col] == v || col + 1 < C && board[row][col+1] == v) {
    return true;
  }

  return false;
}

void remove_at(int row, int col) {
  if (!removable(row, col)) {
    return;
  }

  row = R - row;
  col = col - 1;

  int v = board[row][col];
  board[row][col] = -1;
  queue< pair<int,int> > q;
  pair<int,int> tmp = make_pair(row, col);
  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0 && board[tmp.first-1][tmp.second] == v) {
      board[tmp.first-1][tmp.second] = -1;
      q.push(make_pair(tmp.first-1, tmp.second));
    }

    if (tmp.second > 0 && board[tmp.first][tmp.second-1] == v) {
      board[tmp.first][tmp.second-1] = -1;
      q.push(make_pair(tmp.first, tmp.second-1));
    }

    if (tmp.first + 1 < R && board[tmp.first+1][tmp.second] == v) {
      board[tmp.first+1][tmp.second] = -1;
      q.push(make_pair(tmp.first+1, tmp.second));
    }

    if (tmp.second + 1 < C && board[tmp.first][tmp.second+1] == v) {
      board[tmp.first][tmp.second+1] = -1;
      q.push(make_pair(tmp.first, tmp.second + 1));
    }
  }
}

void remove_column(int col) {
  if (col + 1 == C) {
    return;
  }

  for (int i = 0; i < R; i++) {
    board[i][col] = board[i][col+1];
    board[i][col+1] = -1;
  }

  remove_column(col+1);
}

bool empty_column(int col) {
  for (int i = 0; i < R; i++) {
    if (board[i][col] != -1) {
      return false;
    }
  }

  return true;
}

void remove_empty_columns() {
  for (int i = 0; i < C; i++) {
    if (empty_column(i)) {
      remove_column(i);
      C--;
      i--;
    }
  }
}

bool board_empty() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] != -1) {
        return false;
      }
    }
  }
  
  return true;
}

void show_board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool empty_row(int row) {
  for (int i = 0; i < C; i++) {
    if (board[row][i] != -1) {
      return false;
    }
  }

  return true;
}

bool should_be_dropped_down(int col) {
  bool flag = false;
  for (int i = 0; i < R; i++) {
    if (board[i][col] != -1) {
      flag = true;
    } else {
      if (flag) {
        return true;
      }
    }
  }

  return false;
}

void drop(int row, int col) {
  if (row == 0) {
    return;
  }

  board[row][col] = board[row-1][col];
  board[row-1][col] = -1;

  drop(row-1, col);
}

void drop_down() {
  for (int i = 0; i < C; i++) {
    if (!should_be_dropped_down(i)) {
      continue;
    }

    for (int j = R-1; j >= 0; j--) {
      if (board[j][i] == -1) {
        drop(j, i);
      }
    }

    i--;
  }
}

int main(void)
{
  int row, col, counter = 0;
  int save_R, save_C;

  while (cin >> R >> C) {
    if (R == 0 || C == 0) {
      break;
    }

    save_R = R;
    save_C = C;

    clear_board();
    counter++;

    for (int i = R-1; i >= 0; i--) {
      for (int j = 0; j < C; j++) {
        cin >> board[i][j];
      }
    }

    bool game_won = false;

    while (cin >> row >> col) {
      if (row == 0 && col == 0) {
        break;
      }

      if (game_won) {
        continue;
      }

      remove_at(row, col);
      drop_down();
      remove_empty_columns();

      if (board_empty()) {
        game_won = true;
      }
    }

    cout << "Grid " << counter << "." << endl;
    if (game_won) {
      cout << "    Game Won" << endl;
    } else {
      for (int i = 0; i < save_R; i++) {
        cout << "    ";
        for (int j = 0; j < save_C; j++) {
          if (j > 0) {
            cout << " ";
          }
          if (board[i][j] == -1) {
            cout << " ";
          } else {
            cout << board[i][j];
          }
        }
        cout << endl;
      }
    }

    cout << endl;
  }
  
  return 0;
}
