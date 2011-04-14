#include <iostream>
using namespace std;

int main(void) {
  int n;
  bool ok;
  int result;

  char marks[6] = {'A', 'B', 'C', 'D', 'E', '*'};
  int answers[5];

  while (cin >> n) {
    if (n == 0)
      break;

    while (n--) {
      result = -1;

      for (int i = 0; i < 5; i++)
        cin >> answers[i];

      for (int i = 0; i < 5; i++) {
        if (answers[i] <= 127)
          result = result == -1 ? i : 5;
      }

      if (result == -1)
        result = 5;

      cout << marks[result] << endl;
    }
  }

  return 0;
}
