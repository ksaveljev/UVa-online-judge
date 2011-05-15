#include <iostream>
using namespace std;

int main(void) {
  unsigned long long n, m, tmp;

  while (cin >> n >> m) {
    if (m == 0) {
      cout << 1 << endl;
      continue;
    }

    tmp = 1;
    for (unsigned long long i = n; i >= n - m + 1; i--) {
      tmp *= i;
      while (tmp % 10 == 0)
        tmp /= 10;

      tmp %= 1000000000;
    }

    cout << tmp % 10 << endl;
  }

  return 0;
}
