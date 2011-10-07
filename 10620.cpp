#include <iostream>
using namespace std;

bool is_white(int s, int x, int y) {
  int h = x / s;
  int v = y / s;

  if (x % s == 0 || y % s == 0) {
    return false;
  }

  if (v % 2 == 0) {
    if (h % 2 == 0) {
      return false;
    } else {
      return true;
    }
  } else {
    if (h % 2 == 0) {
      return true;
    } else {
      return false;
    }
  }
}

int main(void)
{
  int s, x, y, dx, dy;

  while (cin >> s >> x >> y >> dx >> dy) {
    if (s == 0 && x == 0 && y == 0 && dx == 0 && dy == 0) {
      break;
    }

    bool can_escape = true;
    int counter = 0;

    while (true) {
      if (is_white(s, x, y)) {
        break;
      }

      if (counter > 10000) {
        can_escape = false;
        break;
      }

      counter++;
      x += dx;
      y += dy;
    }

    if (!can_escape) {
      cout << "The flea cannot escape from black squares." << endl;
    } else {
      cout << "After " << counter << " jumps the flea lands at (" << x << ", " << y << ")." << endl;
    }
  }
  
  return 0;
}
