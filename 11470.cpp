#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int n, tmp, casenum = 0;

  while (cin >> n) {
    if (!n) {
      break;
    }

    casenum++;

    int sums[10] = {0};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> tmp;
        sums[min(min(i, j), min(n-i-1, n-j-1))] += tmp;
      }
    }

    cout << "Case " << casenum << ":";
    for (int i = 0, sz = ceil(n/2.0); i < sz; i++) {
      cout << " " << sums[i];
    }
    cout << endl;
  }

  return 0;
}
