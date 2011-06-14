#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int k, q;
  string a, b;

  cin >> k;
  cin.ignore(100, '\n');

  while (k--) {
    getline(cin, a);

    cin >> q;
    cin.ignore(100, '\n');

    while (q--) {
      getline(cin, b);

      bool result = true;

      if (b.size() > a.size())
        result = false;

      for (int i = 0, sz = b.size(); result && i < sz; i++) {
        if (a[i] != b[i]) {
          result = false;
          break;
        }
      }

      if (result) {
        cout << "y" << endl;
      } else {
        cout << "n" << endl;
      }
    }
  }

  return 0;
}
