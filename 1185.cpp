#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653589793238462643383279502884197169399
#define E 2.71828182845904523536028747135266249775724709369995

int main(void)
{
  int t, n;

  cin >> t;

  while (t--) {
    cin >> n;

    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    long long result = ceil(log10(2 * PI * n) / 2 + n * (log10(n/E)));

    cout << result << endl;
  }
  
  return 0;
}
