#include <iostream>
#include <string>
using namespace std;

int n;
int best;
int result;
char board[4][4];

void print_board() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

bool is_open_position(int a, int b) {
  for (int i = a - 1; i >= 0; i--) {
    if (board[i][b] == 'X')
      break;
    if (board[i][b] == '*')
      return false;
  }

  for (int i = a + 1; i < n; i++) {
    if (board[i][b] == 'X')
      break;
    if (board[i][b] == '*')
      return false;
  }
  
  for (int i = b - 1; i >= 0; i--) {
    if (board[a][i] == 'X')
      break;
    if (board[a][i] == '*')
      return false;
  }

  for (int i = b + 1; i < n; i++) {
    if (board[a][i] == 'X')
      break;
    if (board[a][i] == '*')
      return false;
  }

  return true;
}
void solve(int row, int col) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == '.' && is_open_position(i, j)) {
        board[i][j] = '*';
        //print_board();
        result++;
        if (result > best) {
          best = result;
        }
        solve(i, j + 1);
        result--;
        board[i][j] = '.';
      }
    }
  }
}

int main(void) {
  string input;

  while (cin >> n) {
    if (n == 0)
      break;

    cin.ignore(100, '\n'); 

    for (int i = 0; i < n; i++) {
      getline(cin, input);

      for (int j = 0; j < n; j++)
        board[i][j] = input[j];
    }

    best = 0;
    result = 0;
    solve(0, 0);

    cout << best << endl;
  }

  return 0;
}
