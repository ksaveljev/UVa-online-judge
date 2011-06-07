#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
  int n;

  while (cin >> n) {
    if (n == 0)
      break;

    int L = floor(log(n) - log(2.0) + 1);
    double x = 1 - exp(log(n) - L);

    printf("%d %.8f\n", L, x);
  }

  return 0;
}
