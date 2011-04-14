#include <iostream>
using namespace std;

int main(void) {
  int n;
  int result;

  while (cin >> n) {
    if (n == 0)
      break;

    result = 0;

    while (true) {
      result += n / 3;
      n = n % 3 + n / 3;

      if (n == 0 || n == 1)
        break;
      else if (n == 2) {
        result++;
        break;
      }
    }

    cout << result << endl;
  }

  return 0;
}
