#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int t;
  long long a, b, c;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;

    if (a > b)
      swap(a, b);

    if (b > c)
      swap(b, c);

    cout << "Case " << i+1 << ": ";
    if (c >= a + b) {
      cout << "Invalid" << endl;
    } else if (a == b && b== c) {
      cout << "Equilateral" << endl;
    } else if (a == b || b == c || a == c) {
      cout << "Isosceles" << endl;
    } else {
      cout << "Scalene" << endl;
    }
  }

  return 0;
}
