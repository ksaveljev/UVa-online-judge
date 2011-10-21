#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int year, x;

  while (cin >> year) {
    if (year == 0) {
      break;
    }

    x = pow(2, (year - 1960) / 10 + 2);

    double tmp = 0;
    int result = 0;

    while (x > tmp) {
      result += 1;
      tmp += log2(result);
    }

    cout << result - 1 << endl;
  }
  
  return 0;
}
