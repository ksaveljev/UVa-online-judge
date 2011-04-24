#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct solution {
  int a;
  int b;
};

int main(void) {
  int n;
  int books[10010];
  int money;
  solution best;

  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> books[i];

    cin >> money;

    sort(books, books + n);

    best.a = 0;
    best.b = 2000000000;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == i)
          continue;

        if (books[i] + books[j] == money) {
          if (abs(books[i] - books[j]) < abs(best.a - best.b)) {
            best.a = min(books[i], books[j]);
            best.b = max(books[i], books[j]);
          }
        }
      }
    }

    cout << "Peter should buy books whose prices are " << best.a << " and " << best.b << "." << endl << endl;
  }

  return 0;
}
