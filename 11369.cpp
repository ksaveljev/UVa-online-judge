#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int t, n;
  int result;
  int *p = new int[20000];

  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p[i];

    sort(p, p + n, greater<int>());

    result = 0;
    for (int i = 2; i < n; i += 3)
      result += p[i];

    cout << result << endl;
  }

  delete [] p;

  return 0;
}
