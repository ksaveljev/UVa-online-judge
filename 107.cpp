#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  unsigned long long h, w;
  unsigned long long tmp_h;
  unsigned long long cats;
  unsigned long long height;
  int counter;

  while (cin >> h >> w) {
    if (h == 0 && w == 0)
      break;

    for (int n = 1; ; n++) {
      tmp_h = h;
      counter = 0;
      cats = 1;
      height = h;

      while (tmp_h != 1) {
        if (tmp_h % (n + 1) != 0)
          break;

        tmp_h /= n + 1;
        counter++;
        cats += pow(n, counter);
        height += pow(n, counter) * tmp_h;
      }

      if (tmp_h == 1 && cats >= w) {
        cout << cats - w << " " << height << endl;
        break;
      }
    }
  }

  return 0;
}
