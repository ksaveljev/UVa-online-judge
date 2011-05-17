#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
  int t;
  double c, f;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> c >> f;

    double tmp = 9.0 * c / 5.0 + 32.0;
    tmp += f;

    c = (tmp - 32) * 5 / 9.0;

    cout << "Case " << i+1 << ": ";
    printf("%.2f\n", c);
  }

  return 0;
}
