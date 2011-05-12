#include <iostream>
using namespace std;

int main(void) {
  int n, tmp;
  int counter = 0;
  long long result = 0;

  while (cin >> n) {
    if (n == 0)
      break;

    result = 0;

    counter++;

    for (int i = 1; i < n / 3; i++) {
      tmp = (n - i) / 2;
      if ((n-i)%2 == 0)
        tmp--;
      result += tmp - i;
    }

    cout << "Case " << counter << ": " << result << endl;
  }

  return 0;
}
