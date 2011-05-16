#include <iostream>
using namespace std;

// sphere 4*Pi*r^2
// ring Pi*r^2
// every n > 1 => n * Pi * r^2

int main(void) {
  int n;
  int initial = 4;
  unsigned long long result;

  while (cin >> n) {
    if (n < 0)
      break;

    if (n == 1) {
      result = 0;
    } else {
      // 4 = 100%
      // n = x
      result =  (unsigned long long)n * 100 / 4;
    }

    cout << result << "%" << endl;
  }

  return 0;
}
