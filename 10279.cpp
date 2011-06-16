#include <iostream>
using namespace std;

int main(void) {
  int t, n;
  char bombs[10][10];
  char clicked[10][10];
  int result[12][12];

  cin >> t;

  while (t--) {
    cin >> n;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> bombs[i][j];

    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> clicked[i][j];

        if (clicked[i][j] == 'x' && bombs[i][j] == '*')
          ok = false;
      }
    }

    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
        result[i][j] = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (bombs[i][j] == '.') continue;

        result[i][j+1]++;
        result[i+2][j+1]++;
        result[i+1][j]++;
        result[i+1][j+2]++;
        result[i][j]++;
        result[i+2][j]++;
        result[i][j+2]++;
        result[i+2][j+2]++;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!ok && bombs[i][j] == '*') {
          cout << '*';
          continue;
        }

        if (clicked[i][j] == 'x') {
          cout << result[i+1][j+1];
        } else {
          cout << '.';
        }
      }
      cout << endl;
    }

    if (t)
      cout << endl;
  }

  return 0;
}
