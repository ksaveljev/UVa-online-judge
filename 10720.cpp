#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  int degree[10010];

  while (cin >> n) {
    if (!n)
      break;

    for (int i = 1; i <= n; i++)
      cin >> degree[i];

    sort(degree + 1, degree + n + 1, greater<int>());

    int sum = 0;
    for (int i = 1; i <= n; i++)
      sum += degree[i];

    if (sum % 2 != 0 || degree[1] >= n) {
      cout << "Not possible" << endl;
      continue;
    }

    bool ok = true;
    for (int k = 1; k <= n; k++) {
      sum = 0;
      for (int i = 1; i <= k; i++)
        sum += degree[i];

      int tmp = 0;
      for (int i = k + 1; i <= n; i++)
        tmp += min(degree[i], k);

      tmp += k * (k - 1);

      if (sum > tmp) {
        ok = false;
        break;
      }
    }

    if (ok)
      cout << "Possible" << endl;
    else
      cout << "Not possible" << endl;
  }

  return 0;
}
