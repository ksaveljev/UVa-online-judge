#include <iostream>
using namespace std;

char field[102][102];

void remove_ship(int x, int y)
{
  field[x][y] = '.';

  if (field[x+1][y] == 'x' || field[x+1][y] == '@') {
    remove_ship(x+1, y);
  }

  if (field[x][y+1] == 'x' || field[x][y+1] == '@') {
    remove_ship(x, y+1);
  }

  if (field[x-1][y] == 'x' || field[x-1][y] == '@') {
    remove_ship(x-1, y);
  }

  if (field[x][y-1] == 'x' || field[x][y-1] == '@') {
    remove_ship(x, y-1);
  }
}

int main(void)
{
  int t, n;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> field[i][j];
      }
    }

    int result = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (field[i][j] == 'x') {
          result++;
          remove_ship(i, j);
        }
      }
    }

    cout << "Case " << casenum+1 << ": " << result << endl;
  }

  return 0;
}
