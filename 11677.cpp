#include <iostream>
using namespace std;

int main(void) {
  int h1, m1, h2, m2;

  while (cin >> h1 >> m1 >> h2 >> m2) {
    if (h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0)
      break;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    if (t2 >= t1) {
      cout << t2 - t1 << endl;
    } else {
      cout << 24 * 60 - (t1 - t2) << endl;
    }
  }

  return 0;
}
