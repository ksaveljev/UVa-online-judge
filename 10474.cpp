#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int casenum = 0;
  int n, q, tmp;
  bool found;
  vector<int> marbles;

  while (cin >> n >> q) {
    if (n == 0 && q == 0)
      break;

    casenum++;

    marbles.clear();

    for (int i = 0; i < n; i++) {
      cin >> tmp;
      marbles.push_back(tmp);
    }

    sort(marbles.begin(), marbles.end());

    cout << "CASE# " << casenum << ":" << endl;

    for (int i = 0; i < q; i++) {
      cin >> tmp;

      found = false;
      for (int j = 0, sz = marbles.size(); j < sz; j++) {
        if (marbles[j] == tmp) {
          cout << tmp << " found at " << j + 1 << endl;
          found = true;
          break;
        }
      }
      if (!found)
        cout << tmp << " not found" << endl;
    }
  }

  return 0;
}
