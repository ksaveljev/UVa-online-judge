#include <iostream>
using namespace std;

int calc(int m, int n) {
  if (m == 1 && n == 1)
    return 0;
  if (m == 1)
    return n - 1;
  if (n == 1)
    return m - 1;

  return n-1 + calc(m, 1) * n;
}

int main(void) {
  int m, n;

  while (cin >> m >> n) {
    cout << calc(m, n) << endl;
  }

  return 0;
}
