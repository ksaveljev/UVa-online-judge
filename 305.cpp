#include <iostream>
using namespace std;

int main(void) {
  int n, people;
  int tmp;
  int current;
  int result[15];

  for (int k = 1; k < 14; k++) {
    people = 2 * k;
    for (int m = k + 1; ; m++) {
      if (m % people > 0 && m % people <= k)
        continue;

      tmp = people;
      current = m % people;
      if (current == 0)
        current = people;

      while (tmp > k && current > k) {
        tmp--;
        current = (current - 1 + m) % tmp;
        if (current == 0)
          current = tmp;
      }

      if (tmp == k) {
        result[k] = m;
        break;
      }
    }
  }

  while (cin >> n) {
    if (n == 0)
      break;

    cout << result[n] << endl;
  }

  return 0;
}
