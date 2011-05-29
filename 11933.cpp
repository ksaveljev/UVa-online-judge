#include <iostream>
using namespace std;

int main(void) {
  unsigned int n, a, b;

  while (cin >> n) {
    if (n == 0)
      break;

    a = 0;
    b = 0;
    int counter = 0;

    for (int i = 0; i < 31; i++) {
      if ((n & (1<<i)) != 0) {
        if (counter % 2 == 0) {
          a |= 1 << i;
        } else {
          b |= 1 << i;
        }

        counter++;
      }
    }

    cout << a << " " << b << endl;
  }

  return 0;
}
