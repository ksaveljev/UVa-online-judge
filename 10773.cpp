#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
  int t;
  int d, v, u;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cout << "Case " << i+1 << ": ";

    cin >> d >> v >> u;

    if (v == 0 || v >= u) {
      cout << "can't determine" << endl;
    } else {
      cout << setprecision(3) << fixed << showpoint << abs(d * 1.0 / u - d * 1.0 / sqrt(u*u - v*v)) << endl;
    }
  }

  return 0;
}
