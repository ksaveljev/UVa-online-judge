#include <iostream>
#include <string>
using namespace std;

int main(void) {
  char c;
  int counter = 0;
  string input;
  char board[5][5];
  pair<int,int> blank;

  while (getline(cin,input)) {
    if (input == "Z")
      break;

    if (counter > 0) cout << endl;
    counter++;

    for (int i = 0; i < 5; i++)
      board[0][i] = input[i];

    for (int i = 0; i < 4; i++) {
      getline(cin, input);
      for (int j = 0; j < 5; j++)
        board[i+1][j] = input[j];
    }

    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (board[i][j] == ' ') blank.first = i, blank.second = j;

    bool illegal = false;
    while (cin >> c) {
      if (c == '0')
        break;

      if (illegal) continue;

      switch (c) {
        case 'A':
          if (blank.first > 0) {
            board[blank.first][blank.second] = board[blank.first-1][blank.second];
            board[blank.first-1][blank.second] = ' ';
            blank.first--;
          } else {
            illegal = true;
          }
          break;
        case 'B':
          if (blank.first + 1 < 5) {
            board[blank.first][blank.second] = board[blank.first+1][blank.second];
            board[blank.first+1][blank.second] = ' ';
            blank.first++;
          } else {
            illegal = true;
          }
          break;
        case 'L':
          if (blank.second > 0) {
            board[blank.first][blank.second] = board[blank.first][blank.second-1];
            board[blank.first][blank.second-1] = ' ';
            blank.second--;
          } else {
            illegal = true;
          }
          break;
        case 'R':
          if (blank.second + 1 < 5) {
            board[blank.first][blank.second] = board[blank.first][blank.second+1];
            board[blank.first][blank.second+1] = ' ';
            blank.second++;
          } else {
            illegal = true;
          }
          break;
      }
    }

    cin.ignore(100, '\n');

    cout << "Puzzle #" << counter << ":" << endl;

    if (illegal) {
      cout << "This puzzle has no final configuration." << endl;
      continue;
    }

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (j > 0) cout << " ";
        cout << board[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
