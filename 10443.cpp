#include <iostream>
using namespace std;

char field[102][102];
char new_field[102][102];

bool find(char enemy, int r, int c) {
  if (field[r-1][c] == enemy || field[r+1][c] == enemy || field[r][c-1] == enemy || field[r][c+1] == enemy)
    return true;
  
  return false;
}

int main(void) {
  int t, r, c, n;

  cin >> t;

  while (t--) {
    cin >> r >> c >> n;

    for (int i = 0; i < r+2; i++)
      for (int j = 0; j < c+2; j++)
        field[i][j] = ' ';

    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++)
        cin >> field[i][j];

    for (int days = 0; days < n; days++) {
      for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
          switch(field[i][j]) {
            case 'R':
              new_field[i-1][j-1] = (find('P', i, j) ? 'P' : 'R');
              break;
            case 'S':
              new_field[i-1][j-1] = (find('R', i, j) ? 'R' : 'S');
              break;
            case 'P':
              new_field[i-1][j-1] = (find('S', i, j) ? 'S' : 'P');
              break;
          }
        }
      }

      for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
          field[i][j] = new_field[i-1][j-1];
    }

    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        cout << field[i][j];
      }
      cout << endl;
    }

    if (t)
      cout << endl;
  }

  return 0;
}
