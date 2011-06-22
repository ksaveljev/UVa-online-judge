#include <iostream>
using namespace std;

int main(void) {
  int t, n, iq;
  int result;

  cin >> t;

  while (t--) {
    int best = -1000000000;
    result = -1000000000;

    cin >> n;

    while (n--) {
      cin >> iq;

      if (best - iq > result)
        result = best - iq;

      if (iq > best)
        best = iq;
    }

    cout << result << endl;
  }

  return 0;
}
