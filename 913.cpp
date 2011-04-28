#include <iostream>
using namespace std;

int main(void) {
  unsigned long long n, row, last;

  while (cin >> n) {
    row = (n - 1) / 2;
    last = 2 * row * row + 1 + (n - 1) * 2;
    cout << 3 * last - 6 << endl;
  }

  return 0;
}
