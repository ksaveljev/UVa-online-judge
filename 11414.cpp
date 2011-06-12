#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int t, n;
  int paths[1010];

  cin >> t;
  
  while (t--) {
    cin >> n;

    if (n == 0) {
      cout << "Yes" << endl;
      continue;
    }

    for (int i = 1; i <= n; i++)
      cin >> paths[i];

    sort (paths + 1, paths + n + 1, greater<int>());

    int sum = 0;
    for (int i = 1; i <= n; i++)
      sum += paths[i];

    if (sum % 2 != 0 || paths[1] >= n) {
      cout << "No" << endl;
      continue;
    }

    bool ok = true;
    for (int k = 1; k <= n; k++) {
      sum = 0;
      for (int i = 1; i <= k; i++)
        sum += paths[i];

      int tmp = 0;
      for (int i = k + 1; i <= n; i++)
        tmp += min(paths[i], k);

      tmp += k * (k - 1);

      if (sum > tmp) {
        ok = false;
        break;
      }
    }

    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
