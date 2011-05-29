#include <iostream>
using namespace std;

int main(void) {
  int t;
  int n;
  int h[50];

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }

    int high = 0, low = 0;

    for (int i = 1; i < n; i++) {
      if (h[i] > h[i-1])
        high++;
      else if (h[i] < h[i-1])
        low++;
    }

    cout << "Case " << casenum+1 << ": " << high << " " << low << endl;
  }

  return 0;
}
