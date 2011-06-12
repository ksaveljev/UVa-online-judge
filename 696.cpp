#include <iostream>
using namespace std;

int main(void) {
  int x, y;
  int result;

  while (cin >> x >> y) {
    if (x == 0 && y == 0)
      break;

    if (x == 1 || y == 1) {
      result = max(x, y);
    } else if (x == 2 || y == 2) {
      result = (min((max(x,y) % 4), 2)) * 2 + (max(x,y)/4) * 4;
    } else {
      result = (x * y + 1) / 2;
    }

    cout << result << " knights may be placed on a " << x << " row " << y << " column board." << endl;
  }

  return 0;
}
