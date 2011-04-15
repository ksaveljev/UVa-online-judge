#include <iostream>
using namespace std;

int main(void) {
  int n;
  int tmp;
  int result;
  int e, f, c;

  cin >> n;

  while (n--) {
    cin >> e >> f >> c;

    e += f;
    result = 0;

    while (e >= c) {
      tmp = e / c;
      result += tmp;
      e %= c;
      e += tmp;
    }

    cout << result << endl;
  }

  return 0;
}
