#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
  double a, b, c, s, r;

  while (cin >> a >> b >> c) {
    if (a == 0 && b == 0 && c == 0) {
      cout << "The radius of the round table is: 0.000" << endl;
      continue;
    }
    s = (a + b + c) / 2.0;

    r = sqrt((s - a) * (s - b) * (s - c) / s);
    
    cout << "The radius of the round table is: " << fixed << setprecision(3) << r << endl;
  }

  return 0;
}
