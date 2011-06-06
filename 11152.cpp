#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI 3.1415926535897932384626433832795

int main(void) {
  int a, b, c;

  while (cin >> a >> b >> c) {
    double s = (a + b + c) / 2.0;
    double A = sqrt(s * (s - a) * (s - b) * (s - c));
    double R = (a * b * c) / (4 * A);
    double r = A / s;

    cout << setprecision(4) << fixed << showpoint << PI*R*R - A << " " << A - PI*r*r << " " << PI*r*r << endl;
  }

  return 0;
}
