#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ul;

int main(void) {
  int n;
  int cases;
  ul cars[2001];
  ul lis[2001];
  ul lds[2001];

  cin >> cases;

  while (cases--) {
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> cars[n-i-1];

    fill(lis, lis + n, 1);
    fill(lds, lds + n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (cars[i] > cars[j]) {
          lis[i] = max(lis[i], lis[j] + 1);
        }

        if (cars[i] < cars[j]) {
          lds[i] = max(lds[i], lds[j] + 1);
        }
      }
    }

    ul best = 0;
    for (int i = 0; i < n; i++) {
      //best = max(best, lis[i] + lds[n-i-1] - 1);
      best = max(best, lis[i] + lds[i] - 1);
    }

    cout << best << endl;
  }

  return 0;
}
