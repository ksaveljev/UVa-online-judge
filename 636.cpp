#include <iostream>
#include <cmath>
using namespace std;

int any2dec(int n, int base) {
  int result = 0;
  int count = 0;
  int tmp;

  while (n) {
    tmp = n % 10;
    n /= 10;

    if (tmp >= base)
      return -1;

    result += tmp * pow(base, count);
    count++;
  }

  return result;
}

int main(void) {
  int n, sq, tmp;

  while (cin >> n) {
    if (n == 0)
      break;

    for (int base = 2; base < 100; base++) {
      tmp = any2dec(n, base);

      if (tmp == -1)
        continue;

      sq = sqrt(tmp);
      if (sq * sq == tmp) {
        cout << base << endl;
        break;
      }
    }
  }

  return 0;
}
