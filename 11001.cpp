#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int total, zero;

  while (cin >> total >> zero) {
    if (total == 0 && zero == 0) {
      break;
    }

    int i = 1;
    double v = total * 1.0 / i;
    double best = 0;
    int result = 0;

    while (v > zero) {
      double tmp = 0.3 * sqrt(v - zero);

      if (abs(tmp * i - best) < 0.00000001) {
        result = 0;
        break;
      }

      if (tmp * i > best) {
        best = tmp * i;
        result = i;
      }

      i++;
      v = total * 1.0 / i;
    }

    cout << result << endl;
  }
  
  return 0;
}
