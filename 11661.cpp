#include <iostream>
using namespace std;

int main(void) {
  int L;
  char c;

  while (cin >> L) {
    if (L == 0)
      break;

    int prev_d = -1;
    int prev_r = -1;

    int result = 1000000000;

    bool z_found = false;
    for (int i = 0; i < L; i++) {
      cin >> c;

      if (z_found) continue;

      if (c == '.') continue;

      if (c == 'D') {
        prev_d = i;
        if (prev_r != -1 && prev_d - prev_r < result) {
          result = prev_d - prev_r;
        }
        continue;
      }

      if (c == 'R') {
        prev_r = i;
        if (prev_d != -1 && prev_r - prev_d < result) {
          result = prev_r - prev_d;
        }
        continue;
      }

      if (c == 'Z') {
        z_found = true;
        result = 0;
      }
    }

    cout << result << endl;
  }


  return 0;
}
