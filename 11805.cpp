#include <iostream>
using namespace std;

int main(void) {
  int t, n, k, p;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> n >> k >> p;

    while (p--) {
      k++;
      if (k > n)
        k = 1;
    }

    cout << "Case " << i+1 << ": " << k << endl;
  }

  return 0;
}
