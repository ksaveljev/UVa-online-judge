#include <iostream>
using namespace std;

int main(void)
{
  int n, k;
  int a, b, c, d, t, tmp_a, tmp_b;

  while (cin >> n >> k) {
    a = 0;
    b = 1;
    c = 1;
    d = n;

    while (k--) {
      t = (n + b) / d;
      tmp_a = a;
      tmp_b = b;
      a = c;
      b = d;
      c = t * c - tmp_a;
      d = t * d - tmp_b;
    }

    cout << a << "/" << b << endl;
  }
  
  return 0;
}
