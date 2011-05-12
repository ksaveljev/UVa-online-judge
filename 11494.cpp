#include <iostream>
using namespace std;

bool check_position(int x1, int y1, int x2, int y2) {
  if (y1 == y2 || x1 == x2)
    return true;

  for (int i = 0; x1 - i > 0 && y1 - i > 0; i++) {
    if (x1 - i == x2 && y1 - i == y2)
      return true;
  }

  for (int i = 0; x1 + i < 9 && y1 + i < 9; i++) {
    if (x1 + i == x2 && y1 + i == y2)
      return true;
  }

  for (int i = 0; x1 - i > 0 && y1 + i < 9; i++) {
    if (x1 - i == x2 && y1 + i == y2)
      return true;
  }

  for (int i = 0; x1 + i < 9 && y1 - i > 0; i++) {
    if (x1 + i == x2 && y1 - i == y2)
      return true;
  }

  return false;
}

int main(void) {
  int x1, y1, x2, y2;

  while (cin >> x1 >> y1 >> x2 >> y2) {
    if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
      break;

    if (x1 == x2 && y1 == y2) {
      cout << 0 << endl;
    } else if (check_position(x1, y1, x2, y2)) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }

  return 0;
}
