#include <iostream>
using namespace std;

int main(void) {
  int t, k, h, m, q, best;
  char c;

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> k >> h >> c >> m;

    best = -1;
    int start = h * 60 + m;

    for (int i = 0; i < k; i++) {
      cin >> h >> c >> m >> q;

      int bus = h * 60 + m;
      if (bus < start)
        bus += 24*60;

      int end = bus + q;

      if (end - start < best || best == -1) {
        best = end - start;
      }
    }

    cout << "Case " << casenum+1 << ": " << best << endl;
  }

  return 0;
}
