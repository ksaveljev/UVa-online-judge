#include <iostream>
using namespace std;

int main(void) {
  int r, n;
  int counter;
  int result;

  while (cin >> r >> n) {
    if (r == 0 && n == 0)
      break;

    counter++;

    cout << "Case " << counter << ": ";

    if (n >= r)
      result = 0;
    else if (n * 27 >= r) {
      result = (r - n) / n;
      if ((r-n)%n > 0)
        result += 1;
    } else
      result = -1;

    if (result == -1)
      cout << "impossible" << endl;
    else
      cout << result << endl;
  }

  return 0;
}
