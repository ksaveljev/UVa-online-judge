#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(void) {
  int n, k;
  bool found;
  map<int, bool> squares;

  for (int i = 0; i < 224; i++) {
    squares.insert(make_pair(i*i, true));
  }

  cin >> n;

  while (n--) {
    cin >> k;

    found = false;
    for (int i = 0; i < 224; i++) {
      if (i*i > k)
        break;
      for (int j = i; j < 224; j++) {
        if (i*i + j*j > k)
          break;

        if (squares.find(k - i*i - j*j) != squares.end()) {
          found = true;
          cout << i << " " << j << " " << (int)sqrt(k - i*i - j*j) << endl;
          i = 224;
          break;
        }
      }
    }

    if (!found) {
      cout << "-1" << endl;
    }
  }

  return 0;
}
