#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int n, y, a, b;
  int counter = 0;

  while (cin >> n) {
    if (n == 0) {
      break;
    }

    counter++;

    bool years[10000];
    fill(years, years + 10000, true);

    while (n--) {
      cin >> y >> a >> b;
      for (int i = 0; i < y; i++) {
        years[i] = false;
      }

      for (int i = y; i < 10000; i++) {
        if (i != y && (i - y) % (b - a) != 0) {
          years[i] = false;
        }
      }
    }

    cout << "Case #" << counter << ":" << endl;
    bool ok = false;

    for (int i = 0; i < 10000; i++) {
      if (years[i] == true) {
        ok = true;
        cout << "The actual year is " << i << "." << endl;
        break;
      }
    }

    if (!ok) {
      cout << "Unknown bugs detected." << endl;
    }

    cout << endl;
  }
  
  return 0;
}
