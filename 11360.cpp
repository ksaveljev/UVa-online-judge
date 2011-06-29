#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int tmp[10][10];
int matrix[10][10];

void transpose(int n)
{
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmp[i][j] = matrix[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = tmp[j][i];
    }
  }
}

int main(void)
{
  int t, n, m, a, b;
  char c;
  string instruction;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n;

    for (a = 0; a < n; a++) {
      for (b = 0; b < n; b++) {
        cin >> c;
        matrix[a][b] = c - '0';
      }
    }

    cin >> m;

    while (m--) {
      cin >> instruction;

      if (instruction == "row") {
        cin >> a >> b;
        a--, b--;
        for (int i = 0; i < n; i++) {
          swap(matrix[a][i], matrix[b][i]);
        }
      } else if (instruction == "col") {
        cin >> a >> b;
        a--, b--;
        for (int i = 0; i < n; i++) {
          swap(matrix[i][a], matrix[i][b]);
        }
      } else if (instruction == "inc") {
        for (a = 0; a < n; a++) {
          for (b = 0; b < n; b++) {
            matrix[a][b] = (matrix[a][b] + 1) % 10;
          }
        }
      } else if (instruction == "dec") {
        for (a = 0; a < n; a++) {
          for (b = 0; b < n; b++) {
            matrix[a][b] = (matrix[a][b] + 9) % 10;
          }
        }
      } else if (instruction == "transpose") {
        transpose(n);
      }
    }

    cout << "Case #" << casenum+1 << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j];
      }
      cout << endl;
    }
    
    cout << endl;
  }
  
  return 0;
}
