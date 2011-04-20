#include <iostream>
using namespace std;

int main(void) {
  int n;
  int tmp;

  while (cin >> n) {
    if (n == 0)
      break;

    while (n > 9) {
      tmp = n;
      n = 0;

      while (tmp) {
        n += tmp % 10;
        tmp /= 10;
      }
    }

    cout << n << endl;
  }

  return 0;
}
