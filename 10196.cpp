#include <iostream>
using namespace std;

char board[12][12];

bool find_check(pair<int,int> &king, int offset) {
  int i, j;

  // temporary
  board[king.first][king.second] = '.';

  // up
  for (i = king.first, j = king.second; board[i][j] == '.' && i >= 2; i--);
  if (board[i][j] == char('R' + offset) || board[i][j] == char('Q' + offset))
    return true;

  // down
  for (i = king.first, j = king.second; board[i][j] == '.' && i <= 9; i++);
  if (board[i][j] == char('R' + offset) || board[i][j] == char('Q' + offset))
    return true;

  // left
  for (i = king.first, j = king.second; board[i][j] == '.' && j >= 2; j--);
  if (board[i][j] == char('R' + offset) || board[i][j] == char('Q' + offset))
    return true;

  // right
  for (i = king.first, j = king.second; board[i][j] == '.' && j <= 9; j++);
  if (board[i][j] == char('R' + offset) || board[i][j] == char('Q' + offset))
    return true;

  // up left
  for (i = king.first, j = king.second; board[i][j] == '.' && i >= 2 && j >= 2; i--, j--);
  if (board[i][j] == char('B' + offset) || board[i][j] == char('Q' + offset) || board[i][j] == char('P' + offset) && king.first - i == 1 && king.second - j == 1 && offset == 32)
    return true;

  // up right
  for (i = king.first, j = king.second; board[i][j] == '.' && i >= 2 && j <= 9; i--, j++);
  if (board[i][j] == char('B' + offset) || board[i][j] == char('Q' + offset) || board[i][j] == char('P' + offset) && king.first - i == 1 && j - king.second == 1 && offset == 32)
    return true;

  // down left
  for (i = king.first, j = king.second; board[i][j] == '.' && i <= 9 && j >= 2; i++, j--);
  if (board[i][j] == char('B' + offset) || board[i][j] == char('Q' + offset) || board[i][j] == char('P' + offset) && i - king.first == 1 && king.second - j == 1 && offset == 0)
    return true;

  // down right
  for (i = king.first, j = king.second; board[i][j] == '.' && i <= 9 && j <= 9; i++, j++);
  if (board[i][j] == char('B' + offset) || board[i][j] == char('Q' + offset) || board[i][j] == char('P' + offset) && i - king.first == 1 && j - king.second == 1 && offset == 0)
    return true;

  // knights
  i = king.first; j = king.second;
  if (board[i-2][j-1] == char('N' + offset) || board[i-1][j-2] == char('N' + offset) || board[i+1][j-2] == char('N' + offset) || board[i+2][j-1] == char('N' + offset) || board[i+2][j+1] == char('N' + offset) || board[i+1][j+2] == char('N' + offset) || board[i-1][j+2] == char('N' + offset) || board[i-2][j+1] == char('N' + offset))
    return true;

  // restore temporary change made in the beginning
  board[king.first][king.second] = char('K' + offset);

  return false;
}

int main(void) {
  char c;
  int counter = 0;
  pair<int,int> whiteking, blackking;

  while (cin.peek() != -1) {
    counter++;

    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
        board[i][j] = '.';

    bool empty = true;

    for (int i = 2; i <= 9; i++) {
      for (int j = 2; j <= 9; j++) {
        cin >> board[i][j];
        if (board[i][j] != '.')
          empty = false;
        if (board[i][j] == 'k') {
          blackking.first = i;
          blackking.second = j;
        } else if (board[i][j] == 'K') {
          whiteking.first = i;
          whiteking.second = j;
        }
      }
    }

    if (empty)
      break;

    cin.ignore(100, '\n');

    bool black_check = find_check(blackking, 0);
    bool white_check = find_check(whiteking, 32);

    cout << "Game #" << counter << ": ";
    if (white_check) {
      cout << "white king is in check." << endl;
    } else if (black_check) {
      cout << "black king is in check." << endl;
    } else {
      cout << "no king is in check." << endl;
    }
  }

  return 0;
}
