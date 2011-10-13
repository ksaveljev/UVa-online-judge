#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int t;
  int n, m;
  int p1, p2;
  int list1[10001], list2[10001];

  cin >> t;

  while (t--) {
    cin >> n >> m;

    int result = 0;

    for (int i = 0; i < n; i++) {
      cin >> list1[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> list2[i];
    }

    sort(list1, list1 + n);
    sort(list2, list2 + m);

    p1 = p2 = 0;

    while (p1 < n || p2 < m) {
      if (p1 == n) {
        result++;
        p2++;
        continue;
      }

      if (p2 == m) {
        result++;
        p1++;
        continue;
      }

      if (list1[p1] < list2[p2]) {
        result++;
        p1++;
      } else if (list1[p1] > list2[p2]) {
        result++;
        p2++;
      } else {
        p1++;
        p2++;
      }
    }

    cout << result << endl;
  }
  
  return 0;
}
