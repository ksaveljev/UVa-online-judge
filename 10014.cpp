#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
  int cases, n;
  double a0, aNp1;
  double c[3001];

  cin >> cases;

  while (cases--) {
    cin >> n;
    cin >> a0 >> aNp1;

    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }

    double result = n * a0 + aNp1;
    for (int i = n; i >= 1; i--) {
      result -= c[i] * 2 * (n-i+1);
    }

    cout << setprecision(2) << fixed << showpoint << result / (n + 1) << endl;

    if (cases) {
      cout << endl;
    }
  }
  
  return 0;
}
