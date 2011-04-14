#include <iostream>
using namespace std;

int main(void) {
  int a, b, c;
  char action, eq;
  int result = 0;

  while (cin >> a >> action >> b >> eq) {
    if (cin.peek() == '?') {
      cin >> eq;
      continue;
    }

    cin >> c;

    if (action == '+') {
      if (a + b == c)
        result++;
    } else {
      if (a - b == c)
        result++;
    }
  }

  cout << result << endl;

  return 0;
}
