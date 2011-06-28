#include <iostream>
using namespace std;

int main(void)
{
  int a, b, c, d, L;
  int result;

  while (cin >> a >> b >> c >> d >> L) {
    if (!a && !b && !c && !d && !L) {
      break;
    }

    result = 0;

    for (int i = 0; i <= L; i++) {
      if ((a * i * i + b * i + c) % d == 0) {
        result++;
      }
    }

    cout << result << endl;
  }

  return 0;
}
