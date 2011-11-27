#include <iostream>
using namespace std;

int main(void)
{
  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;

    int result = -1;

    for (int h = 1; h <= n; h++) {
      for (int w = 1; w <= n; w++) {
        if (h * w > n) continue;
        for (int l = 1; l <= n; l++) {
          if (h * w * l != n) continue;

          int tmp = l * w * 2 + h * w * 2 + h * l * 2;

          if (result == -1 || tmp < result) {
            result = tmp;
          }
        }
      }
    }

    cout << result << endl;
  }
  
  return 0;
}
