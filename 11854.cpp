#include <iostream>
using namespace std;

int main(void) {
  int a, b, c;

  while (cin >> a >> b >> c) {
    if (a == 0 && b == 0 && c == 0)
      break;

    if (a > b)
      swap(a, b);

    if (b > c)
      swap(b, c);

    if (c*c == a*a + b*b)
      cout << "right" << endl;
    else
      cout << "wrong" << endl;
  }

  return 0;
}
