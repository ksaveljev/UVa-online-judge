#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int n, m;
  long nums[1000];
  long result[1000000];
  int casenum = 0;

  while (cin >> n) {
    if (!n)
      break;

    casenum++;

    for (int i = 0; i < n; i++)
      cin >> nums[i];

    int pos = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (nums[i] == nums[j]) continue;
        result[pos] = nums[i] + nums[j];
        pos++;
      }
    }

    sort(result, result+pos);

    cin >> m;

    int tmp;

    cout << "Case " << casenum << ":" << endl;

    while (m--) {
      cin >> tmp;

      int best = -1;
      for (int i = 0; i < pos; i++) {
        if (result[i] > tmp) {
          if (best == -1 || result[i] - tmp < tmp - best)
            best = result[i];
          break;
        }

        best = result[i];
      }

      cout << "Closest sum to " << tmp << " is " << best << "." << endl;
    }
  }

  return 0;
}
