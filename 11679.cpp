#include <iostream>
using namespace std;

int main(void)
{
  int b, n, debtor, creditor, value;

  while (cin >> b >> n) {
    if (b == 0 && n == 0) {
      break;
    }

    int banks[b];

    for (int i = 0; i < b; i++) {
      cin >> banks[i];
    }

    while (n--) {
      cin >> debtor >> creditor >> value;
      banks[debtor-1] -= value;
      banks[creditor-1] += value;
    }

    bool ok = true;

    for (int i = 0; i < b; i++) {
      if (banks[i] < 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "S" << endl;
    } else {
      cout << "N" << endl;
    }
  }
  
  return 0;
}
