#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int n;
  int result;
  bool ok;

  while (cin >> n) {
    if (n < 0)
      break;

    result = -1;

    for (int i = sqrt(n) + 1; i >= 2; i--) {
      int tmp = n;

      ok = true;
      for (int j = 0; j < i; j++) {
        if (tmp % i != 1) {
          ok = false;
          break;
        }

        tmp -= tmp / i; // hidden
        tmp--; // goes to monkey
      }

      if (!ok)
        continue;

      if (tmp % i == 0) {
        result = i;
        break;
      }
    }

    cout << n << " coconuts, ";
    if (result == -1) {
      cout << "no solution" << endl;
    } else {
      cout << result << " people and 1 monkey" << endl;
    }
  }

  return 0;
}
