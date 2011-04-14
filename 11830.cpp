#include <iostream>
#include <string>
using namespace std;

int main(void) {
  char n;
  bool first;
  string contract;

  while (cin >> n >> contract) {
    if (n == '0' && contract == "0")
      break;

    first = true;
    for (int i = 0, sz = contract.size(); i < sz; i++) {
      if (contract[i] == n)
        continue;

      if (contract[i] == '0') {
        if (first)
          continue;
      }

      cout << contract[i];
      first = false;
    }

    if (first)
      cout << 0;

    cout << endl;
  }

  return 0;
}
