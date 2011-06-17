#include <iostream>
#include <string>
using namespace std;

char board[12][12];

void fill(int r, int c) {
  int i, j;

  switch (board[r][c]) {
    case 'K':
    case 'k':
      if (board[r-1][c] == '.') board[r-1][c] = '*';
      if (board[r+1][c] == '.') board[r+1][c] = '*';
      if (board[r][c-1] == '.') board[r][c-1] = '*';
      if (board[r][c+1] == '.') board[r][c+1] = '*';
      if (board[r-1][c-1] == '.') board[r-1][c-1] = '*';
      if (board[r+1][c-1] == '.') board[r+1][c-1] = '*';
      if (board[r-1][c+1] == '.') board[r-1][c+1] = '*';
      if (board[r+1][c+1] == '.') board[r+1][c+1] = '*';
      break;
    case 'Q':
    case 'q':
      for (i = r-1; i >= 2 && (board[i][c] == '.' || board[i][c] == '*'); board[i][c] = '*', i--);
      for (i = r+1; i < 10 && (board[i][c] == '.' || board[i][c] == '*'); board[i][c] = '*', i++);
      for (i = c-1; i >= 2 && (board[r][i] == '.' || board[r][i] == '*'); board[r][i] = '*', i--);
      for (i = c+1; i < 10 && (board[r][i] == '.' || board[r][i] == '*'); board[r][i] = '*', i++);
      for (i = r-1, j = c-1; i >= 2 && j >= 2 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i--, j--);
      for (i = r+1, j = c-1; i < 10 && j >= 2 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i++, j--);
      for (i = r-1, j = c+1; i >= 2 && j < 10 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i--, j++);
      for (i = r+1, j = c+1; i < 10 && j < 10 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i++, j++);
      break;
    case 'R':
    case 'r':
      for (i = r-1; i >= 2 && (board[i][c] == '.' || board[i][c] == '*'); board[i][c] = '*', i--);
      for (i = r+1; i < 10 && (board[i][c] == '.' || board[i][c] == '*'); board[i][c] = '*', i++);
      for (i = c-1; i >= 2 && (board[r][i] == '.' || board[r][i] == '*'); board[r][i] = '*', i--);
      for (i = c+1; i < 10 && (board[r][i] == '.' || board[r][i] == '*'); board[r][i] = '*', i++);
      break;
    case 'N':
    case 'n':
      if (board[r-2][c-1] == '.') board[r-2][c-1] = '*';
      if (board[r-1][c-2] == '.') board[r-1][c-2] = '*';
      if (board[r+1][c-2] == '.') board[r+1][c-2] = '*';
      if (board[r+2][c-1] == '.') board[r+2][c-1] = '*';
      if (board[r+2][c+1] == '.') board[r+2][c+1] = '*';
      if (board[r+1][c+2] == '.') board[r+1][c+2] = '*';
      if (board[r-1][c+2] == '.') board[r-1][c+2] = '*';
      if (board[r-2][c+1] == '.') board[r-2][c+1] = '*';
      break;
    case 'B':
    case 'b':
      for (i = r-1, j = c-1; i >= 2 && j >= 2 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i--, j--);
      for (i = r+1, j = c-1; i < 10 && j >= 2 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i++, j--);
      for (i = r-1, j = c+1; i >= 2 && j < 10 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i--, j++);
      for (i = r+1, j = c+1; i < 10 && j < 10 && (board[i][j] == '.' || board[i][j] == '*'); board[i][j] = '*', i++, j++);
      break;
    case 'P':
      if (board[r-1][c-1] == '.') board[r-1][c-1] = '*';
      if (board[r-1][c+1] == '.') board[r-1][c+1] = '*';
      break;
    case 'p':
      if (board[r+1][c-1] == '.') board[r+1][c-1] = '*';
      if (board[r+1][c+1] == '.') board[r+1][c+1] = '*';
      break;
  }
}

int main(void) {
  char tmp;
  string input;

  while (getline(cin,input)) {
    if (input == "")
      break;

    int r = 2;
    int c = 2;

    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
        board[i][j] = '.';

    for (int i = 0; i < input.size(); i++) {
      tmp = input[i];

      if (tmp == '/') {
        r++;
        c = 2;
        continue;
      }

      if (tmp >= '1' && tmp <= '8') {
        for (int i = 0; i < int(tmp - '0'); i++) {
          c++;
        }
      } else {
        board[r][c] = tmp;
        c++;
      }
    }

    for (int i = 2; i < 10; i++) {
      for (int j = 2; j < 10; j++) {
        if (board[i][j] != '.' && board[i][j] != '*')
          fill(i, j);
      }
    }

    int result = 0;
    for (int i = 2; i < 10; i++)
      for (int j = 2; j < 10; j++)
        if (board[i][j] == '.')
          result++;

    cout << result << endl;
  }

  return 0;
}
