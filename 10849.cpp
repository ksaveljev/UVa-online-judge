#include <iostream>
#include <cstdlib>
using namespace std;

bool iswhite(int x, int y) {
  if (x % 2 == 0 && y % 2 == 1 || x % 2 == 1 && y % 2 == 0)
    return true;

  return false;
}

int main(void) {
  int t, c, n;
  int x1, y1, x2, y2;

  cin >> t;

  while (t--) {
    cin >> c >> n;

    for (int i = 0; i < c; i++) {
      cin >> x1 >> y1 >> x2 >> y2;

      if (x1 > n || x2 > n || y1 > n || y2 > n) {
        cout << "no move" << endl;
        continue;
      }

      if (x1 == x2 && y1 == y2) {
        cout << 0 << endl;
        continue;
      }

      if (abs(x1-x2) == abs(y1-y2) || x1+y1 == x2+y2) {
        cout << 1 << endl;
        continue;
      }

      if (iswhite(x1, y1) && iswhite(x2, y2) || !iswhite(x1, y1) && !iswhite(x2, y2)) {
        cout << 2 << endl;
        continue;
      }

      cout << "no move" << endl;
    }
  }

  return 0;
}
