#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int n, m;
  int heads[20000];
  int knights[20000];

  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> heads[i];

    for (int i = 0; i < m; i++)
      cin >> knights[i];

    if (m < n) {
      cout << "Loowater is doomed!" << endl;
      continue;
    }

    sort(heads, heads + n);
    sort(knights, knights + m);

    int result = 0;

    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (n - i > m - cur) {
        result = -1;
        break;
      }
      for (int j = cur; j < m; j++) {
        if (knights[j] < heads[i]) {
          cur++;
          continue;
        }

        result += knights[j];
        cur++;
        break;
      }
    }

    if (result == -1) {
      cout << "Loowater is doomed!" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
