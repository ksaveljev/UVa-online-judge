#include <iostream>
using namespace std;

int main(void)
{
  int n;
  int a, b, c;

  cin >> n;

  while (n--) {
    cin >> a >> b >> c;

    bool found = false;
    for (int i = -100; i <= 100; i++) {
      for (int j = -100; j <= 100; j++) {
        for (int k = -100; k <= 100; k++) {
          if (i != j && i != k && j != k && i + j + k == a && i * j * k == b && i*i + j*j + k*k == c) {
            found = true;
            cout << i << " " << j << " " << k << endl;
            i = j = 101;
            break;
          }
        }
      }
    }

    if (!found) {
      cout << "No solution." << endl;
    }
  }

  return 0;
}
