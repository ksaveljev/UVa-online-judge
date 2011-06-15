#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int n, x;
  int cards[20];
  bool p[51];
  int selection = 0;

  while (cin >> n >> x) {
    selection++;

    for (int i = 0; i < 20; i++)
      cin >> cards[i];

    fill(p, p+51, true);
    int left = n;

    for (int i = 0; i < 20 && left > x; i++) {
      int counter = 0;
      for (int j = 1; j <= n; j++) {
        if (p[j] == true)
          counter++;

        if (counter == cards[i]) {
          counter = 0;
          p[j] = false;
          left--;
        }

        if (left == x) {
          i = 21;
          break;
        }
      }
    }

    cout << "Selection #" << selection << endl;
    bool first = true;
    for (int i = 1; i <= n; i++) {
      if (p[i] == true) {
        if (!first) cout << " ";
        cout << i;
        first = false;
      }
    }
    cout << endl << endl;
  }

  return 0;
}
