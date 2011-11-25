#include <iostream>
using namespace std;

int main(void)
{
  int m, n, v;
  int field[101][101];

  while (cin >> m >> n) {
    if (m == 0 && n == 0) {
      break;
    }

    int best = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v;
        if (j == 0) {
          if (v == 0) {
            field[i][j] = 1;
            if (field[i][j] > best) {
              best = field[i][j];
            }
          } else {
            field[i][j] = 0;
          }
        } else {
          if (v == 0) {
            field[i][j] = field[i][j-1] + 1;
            if (field[i][j] > best) {
              best = field[i][j];
            }
          } else {
            field[i][j] = 0;
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (field[i][j] > 0) {
          int rows = 1;
          int cols = field[i][j];

          for (int k = i+1; k < m; k++) {
            if (field[k][j] == 0) break;

            cols = min(cols, field[k][j]);
            rows++;

            if (rows * cols > best) {
              best = rows * cols;
            }
          }
        }
      }
    }

    cout << best << endl;
  }
  
  return 0;
}
