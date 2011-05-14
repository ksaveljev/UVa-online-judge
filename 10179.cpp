#include <iostream>
#include <cmath>
using namespace std;

int phi(int n) {
  int result = n;

  if (n % 2 == 0) {
    while (n % 2 == 0)
      n /= 2;
    result -= result / 2;
  }

  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0) {
      while (n % i == 0)
        n /= i;
      result -= result / i;
    }
  }

  if (n > 1)
    result -= result / n;

  return result;
}

int main(void) {
  int n;

  while (cin >> n) {
    if (n == 0)
      break;

    cout << phi(n) << endl;
  }

  return 0;
}
