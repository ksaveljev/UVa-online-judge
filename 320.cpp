#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int cases, col, row;
  string movement;

  cin >> cases;

  for (int case_num = 0; case_num < cases; case_num++) {
    cin >> col >> row;

    char bitmap[32][32];

    for (int i = 0; i < 32; i++) {
      for (int j = 0; j < 32; j++) {
        bitmap[i][j] = '.';
      }
    }

    cin >> movement;

    for (int i = 0, sz = movement.size(); i < sz; i++) {
      if (movement[i] == '.')
        break;

      switch(movement[i]) {
        case 'W':
          bitmap[row][col-1] = 'X';
          col--;
          break;
        case 'E':
          bitmap[row-1][col] = 'X';
          col++;
          break;
        case 'N':
          bitmap[row][col] = 'X';
          row++;
          break;
        case 'S':
          bitmap[row-1][col-1] = 'X';
          row--;
          break;
      }
    }

    cout << "Bitmap #" << case_num + 1 << endl;
    for (int i = 31; i >= 0; i--) {
      for (int j = 0; j < 32; j++) {
        cout << bitmap[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  
  return 0;
}
