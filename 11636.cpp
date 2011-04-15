#include <iostream>
using namespace std;

int main(void) {
  int n;
  int powers[15];
  int cases = 0;

  powers[0] = 1;
  for (int i = 1; i < 15; i++) {
    powers[i] = powers[i-1] * 2;
  }

  while (cin >> n) {
    if (n < 0)
      break;

    cases++;
    for (int i = 0; i < 15; i++) {
      if (powers[i] >= n) {
        cout << "Case " << cases << ": " << i << endl;
        break;
      }
    }
  }

  return 0;
}
