#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  int a, b, c;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;

    if (a > b)
      swap(a, b);

    if (b > c)
      swap(b, c);

    if (a + b <= c)
      cout << "Wrong!!" << endl;
    else
      cout << "OK" << endl;
  }

  return 0;
}
